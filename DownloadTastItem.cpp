#include "DownloadTastItem.h"


DownloadTastItem::DownloadTastItem(const string& path, const string& projName, const string& filename, size_t filesize, QListWidgetItem* p, QWidget* parent)
	:TaskItem(DOWNLOAD, filename, filesize, p, path, projName, parent)
{
	start();
}

void DownloadTastItem::task() {

	start_time = time(NULL);
	record_time = start_time;
	QString pathname = QString::fromStdString(path + filename);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(pathname).data();
	qDebug() << "File = " << name.c_str() << endl;

	//检测本地已完成文件
	size_t fs = get_file_size(path + filename);
	//文件存在
	if (fs > 0) {
		//为同一文件
		if (fs == filesize) {
			emit complete(FILE_EXISTS);
			return;
		}
		//不同名
		else {
			emit complete(FILE_NAME_DULPLICTAION);
			return;
		}
	}
	//检测本地未完成文件
	fs = get_file_size(path + filename + ".ft.nc");

	fstream ofs(name + ".ft.nc", ios::out | ios::binary | ios::app);
	//if (!ofs) {
	//	qDebug() << "File open failed" << endl;
	//	emit complete(1);
	//	return;
	//}
	struct addrinfo hints, *peer, *local;
	int64_t offset = fs;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	UDTSOCKET fhandle = UDT::socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
	int timeout = 10000;
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
	qDebug() << filename.c_str() << " " << filesize << endl;
	FileRequest msg((char)DOWNLOAD, my_email.c_str(), my_token.c_str(), projectName.c_str(), filename.c_str(), filesize, 0, fs);
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
	if (rpy.op != DOWNLOAD) {
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
	filesize = rpy.file_size;
	emit updateFilesize(filesize);
	qDebug() << "offset = " << offset << endl;
	std::thread monitor{ [this, &trace, fhandle, &offset] {
			int i = 10;
			while (!stop) {
				Sleep(100);
				if (fhandle == INVALID_SOCKET || UDT::perfmon(fhandle, &trace) == UDT::ERROR) break;
				if (++i >= 10) {
					i = 0;
					int remain_sec = 0;
					if (trace.mbpsRecvRate < 0.0005) remain_sec = -1;
					else remain_sec = (((filesize - offset) << 3) >> 20) / trace.mbpsRecvRate;
					emit update_speed(trace.mbpsRecvRate, remain_sec);
				}
				emit update_pb(offset * 100 / filesize);
			}
	} };
	monitor.detach();
	char buffer[CHUNK_SIZE];
	ofs.seekp(offset, ios::beg);
	size_t remainSize = filesize - offset;
	qDebug() << "Remainsize = " << remainSize << endl;
	//if (UDT::ERROR == UDT::recvfile(fhandle, ofs, offset, remainSize)) {
	//	UDT::close(fhandle);
	//	ofs.close();
	//	qDebug() << "recvfile: " << UDT::getlasterror().getErrorMessage() << endl;
	//	emit complete(1);
	//	return;
	//}
	while (remainSize) {
		int ret = 0;
		if (stop) {
			UDT::close(fhandle);
			ofs.close();
			qDebug() << "Stop by user";
			emit complete(STOP_BY_USER);
			return;
		}
		if (pause) {
			int ret;
			if ((ret = UDT::recv(fhandle, NULL, 0, 0))==UDT::ERROR) {
				UDT::close(fhandle);
				ofs.close();
				qDebug() << "recv: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(RECV_FILE_ERROR);
				return;
			}
			//qDebug() << "Pausing ret = " << ret << endl;
			Sleep(100);
			continue;
		}
		if (remainSize >= CHUNK_SIZE) {
			if (UDT::ERROR == (ret=gRecv(fhandle, buffer, CHUNK_SIZE, 0))) {
				UDT::close(fhandle);
				ofs.close();
				qDebug() << "recvfile: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(RECV_FILE_ERROR);
				return;
			}
			ofs.write(buffer, CHUNK_SIZE);
			offset += CHUNK_SIZE;
			remainSize -= CHUNK_SIZE;
		}
		else {
			if (UDT::ERROR == (ret= gRecv(fhandle, buffer, remainSize, 0))) {
				UDT::close(fhandle);
				ofs.close();
				qDebug() << "recvfile: " << UDT::getlasterror().getErrorMessage() << endl;
				emit complete(RECV_FILE_ERROR);
				return;
			}
			ofs.write(buffer, remainSize);
			offset += remainSize;
			remainSize -= remainSize;
		}
		//qDebug() << "Remain = " << remainSize << " send = " << ret << endl;
		
	}
	
	ofs.close();
	UDT::close(fhandle);
	rename(string(name + ".ft.nc").c_str(), name.c_str());

	//校验下载文件
	if (hashFile((path + filename).c_str()) != string(rpy.fileHash)) {
		qDebug() << "FileHash: failed to hash file" << hashFile((path + filename).c_str()).c_str() << string(rpy.fileHash).c_str();
		emit complete(FILE_HASH_FAULT);
		return;
	}

	// use this function to release the UDT library
	emit update_pb(100);
	emit complete(MY_NO_ERROR);
	qDebug() << "File recv done" << endl;
	return;
}



DownloadTastItem::~DownloadTastItem()
{
}
