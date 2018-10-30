#include "UploadTaskItem.h"

UploadTaskItem::UploadTaskItem(const string& path, int typeId,const string& projName, QListWidgetItem* p, QWidget* parent) :
	TaskItem(UPLOAD, get_file_name(path), get_file_size(path), p, path,typeId, projName, parent)
{
	start();
}

UploadTaskItem::~UploadTaskItem()
{
}

void UploadTaskItem::task()
{
	start_time = time(NULL);
	record_time = start_time;
	QString pathname = QString::fromStdString(path);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(pathname).data(); 

	QString qfilename = QString::fromStdString(filename);
	code = QTextCodec::codecForName("utf-8");//解决中文路径问题
	string cnfilename = code->fromUnicode(qfilename).data();

	fstream ifs(name, ios::in | ios::binary);
	qDebug() << "UploadFIle = " << path.c_str() << endl;
	if (!ifs) {
		qDebug() << "File open failed" << endl;
		emit complete(FILE_OPEN_FAILED);
		return;
	}
	struct addrinfo hints, *peer, *local;
	fileHash = hashFile(path.c_str());

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	UDTSOCKET fhandle = UDT::socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
	int timeout = 15000;
	UDT::setsockopt(fhandle, 0, UDT_SNDTIMEO, (char*)&timeout, sizeof(int));
	UDT::setsockopt(fhandle, 0, UDT_RCVTIMEO, (char*)&timeout, sizeof(int));
	if (0 != getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &peer))
	{
		qDebug() << "incorrect server/peer address. " << SERVER_IP << ":" << SERVER_PORT << endl;
		emit complete(INCORRECT_ADDR);
		return;
	}
	// connect to the server, implict bind
	if (UDT::ERROR == UDT::connect(fhandle, peer->ai_addr, peer->ai_addrlen))
	{
		qDebug() << "connect: " << UDT::getlasterror().getErrorMessage() << endl;
		emit complete(CONNECT_FAILED);
		return;
	}
	freeaddrinfo(peer);
	qDebug() << filename.c_str() << " " << filesize << " " << fileHash.c_str() << endl;
	FileRequest msg((char)UPLOAD, my_email.c_str(), my_token.c_str(), TYPE[typeId].c_str(), projectName.c_str(), cnfilename.c_str(), filesize, fileHash.c_str());
	if (UDT::ERROR == UDT::send(fhandle, (char*)&msg, sizeof(msg), 0)) {
		qDebug() << "send msg: " << UDT::getlasterror().getErrorMessage() << endl;
		emit complete(SEND_REQ_FAILED);
		return;
	}
	FileReply rpy;
	if (UDT::ERROR == UDT::recv(fhandle, (char*)&rpy, sizeof(rpy), 0)) {
		qDebug() << "recv msg: " << UDT::getlasterror().getErrorMessage() << endl;
		emit complete(RECV_REPLY_FAILED);
		return;
	}
	if (rpy.op != UPLOAD || rpy.file_size != 0) {
		qDebug() << "Msg reply error" << endl;
		emit complete(REPLY_ERROR);
		return;
	}
	if (rpy.error_flag != MY_NO_ERROR) {
		qDebug() << rpy.extra << endl;
		emit complete(rpy.error_flag);
		return;
	}
	UDT::TRACEINFO trace;
	UDT::perfmon(fhandle, &trace);
	size_t offset = rpy.offset;
	qDebug() << "offset = " << offset << endl;
	std::thread monitor{ [this, &trace, fhandle, &offset] {
			int i = 10;
			while (!stop) {
				if (fhandle == INVALID_SOCKET || UDT::perfmon(fhandle, &trace) == UDT::ERROR) break;
				if (++i >= 3) {
					i = 0;
					int remain_sec = 0;
					if (trace.mbpsSendRate < 0.0005) remain_sec = -1;
					else remain_sec = (((filesize - offset) << 3) >> 20) / trace.mbpsSendRate;
					emit update_speed(trace.mbpsSendRate, remain_sec);
				}
				emit update_pb(offset*100 / filesize);
				Sleep(333);
			}
	} };
	monitor.detach();
	//if (UDT::ERROR == UDT::sendfile(fhandle, ifs, offset, filesize)) {
	//	UDT::close(fhandle);
	//	ifs.close();
	//	qDebug() << "sendfile: " << UDT::getlasterror().getErrorMessage() << endl;
	//	emit complete(1);
	//	return -1;
	//}
	char buffer[CHUNK_SIZE];
	ifs.seekg(offset, ios::beg);
	size_t remainSize = filesize - offset;
	qDebug() << "SIZE = " << filesize << " " << offset << " " << remainSize << endl;
	while (remainSize) {
		if (stop) {
			UDT::close(fhandle);
			ifs.close();
			qDebug() << "Stop by user";
			emit complete(STOP_BY_USER);
			return;
		}
		if (pause) {
			if (UDT::ERROR == gSend(fhandle, NULL, 0, 0)) {
				UDT::close(fhandle);
				ifs.close();
				qDebug() << "send: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(SEND_FILE_ERROR);
				return;
			}
			Sleep(100);
			continue;
		}
		if (remainSize >= CHUNK_SIZE) {
			ifs.read(buffer, CHUNK_SIZE);
			if (UDT::ERROR == gSend(fhandle, buffer, CHUNK_SIZE, 0)) {
				UDT::close(fhandle);
				ifs.close();
				qDebug() << "send: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(SEND_FILE_ERROR);
				return;
			}
			offset += CHUNK_SIZE;
			remainSize -= CHUNK_SIZE;
		}
		else {
			ifs.read(buffer, remainSize);
			if (UDT::ERROR == gSend(fhandle, buffer, remainSize, 0)) {
				UDT::close(fhandle);
				ifs.close();
				qDebug() << "send: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(SEND_FILE_ERROR);
				return;
			}
			offset += remainSize;
			remainSize -= remainSize;
		}
	}
	//接受服务器发送回来的文件校验结果
	if (UDT::ERROR == UDT::recv(fhandle, (char*)&rpy, sizeof(rpy), 0)) {
		qDebug() << "recv msg: " << UDT::getlasterror().getErrorMessage() << endl;
		emit complete(RECV_REPLY_FAILED);
		return;
	}
	if (rpy.error_flag != MY_NO_ERROR) {
		qDebug() << rpy.extra << endl;
		emit complete(rpy.error_flag);
		return;
	}
	qDebug() << "文件校验成功";
	ifs.close();
	UDT::close(fhandle);
	// use this function to release the UDT library
	emit update_pb(100);
	emit complete(MY_NO_ERROR);
	qDebug() << "File send done" << endl;
	return;
}
