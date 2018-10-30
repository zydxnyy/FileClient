#include "util.h"
#include "HttpOp.h"
#include<qmessagebox.h>
#include <qsettings.h>

string	my_token = "";
string	my_email = "";
int		my_uid = -1;

QSettings* psetting = new QSettings("win.ini", QSettings::IniFormat);
const string WEB_SERVER_IP = psetting->value("WEB_SERVER_IP", "114.67.37.2").toString().toStdString();
const string WEB_SERVER_PORT = psetting->value("WEB_SERVER_PORT", "10422").toString().toStdString();
const string FILE_SERVER_IP = psetting->value("FILE_SERVER_IP", "114.67.37.2").toString().toStdString();
const string FILE_SERVER_PORT = psetting->value("FILE_SERVER_PORT", "20574").toString().toStdString();


//const string WEB_SERVER_IP = setting->value("WEB_SERVER_IP", "192.168.135.131").toString().toStdString();
//const string WEB_SERVER_PORT = setting->value("WEB_SERVER_PORT", "9091").toString().toStdString();;
//const string FILE_SERVER_IP = setting->value("FILE_SERVER_IP", "192.168.135.131").toString().toStdString();
//const string FILE_SERVER_PORT = setting->value("FILE_SERVER_PORT", "5566").toString().toStdString();

const string ERROR_STR[] = {
	"NO_ERROR",
	"ERROR",
	"用户登录已过期，请重新验证",
	"文件已经存在",
	"文件不存在",
	"服务器内部错误",
	"文件名重复",
	"打开文件失败",
	"服务器地址错误",
	"服务器连接失败",
	"发送文件请求失败",
	"接受文件响应失败",
	"文件响应错误",
	"传输过程被终止",
	"接收文件的过程中检测到错误",
	"发送文件的过程中检测到错误",
	"用户权限非法",
	"文件校验失败",
};

const string TYPE[] = { "Protein", "Drug", "Animal" };

string browse_file()
{
	QString fileName = QFileDialog::getOpenFileName(NULL, "Open file", ".", "All Files(*.*)");
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(fileName).data();

	if (fileName.isEmpty())
	{
		return "";
	}

	return name;
}

bool compareIgnoreCase(const string & s1, const string & s2)
{
	if (s1.size() != s2.size()) return false;

	for (int i = 0; i < s1.size(); ++i) {
		if (tolower(s1[i]) != tolower(s2[i])) return false;
	}
	return true;
}

Py_Ret login(const string& email, const string& password) {
	return verify_account(email, password);
}

Py_Ret get_all_project(const string& email, const string& token) {
	struct addrinfo hints, *peer, *local;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	UDTSOCKET fhandle = UDT::socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
	int timeout = 1000;
	UDT::setsockopt(fhandle, 0, UDT_SNDTIMEO, (char*)&timeout, sizeof(int));
	UDT::setsockopt(fhandle, 0, UDT_RCVTIMEO, (char*)&timeout, sizeof(int));
	if (0 != getaddrinfo(FILE_SERVER_IP.c_str(), FILE_SERVER_PORT.c_str(), &hints, &peer))
	{
		qDebug() << "incorrect server/peer address. " << FILE_SERVER_IP.c_str() << ":" << FILE_SERVER_PORT.c_str() << endl;
		return Py_Ret(-1, "Failed to get address", -1);
	}
	// connect to the server, implict bind
	if (UDT::ERROR == UDT::connect(fhandle, peer->ai_addr, peer->ai_addrlen))
	{
		qDebug() << "connect: " << UDT::getlasterror().getErrorMessage() << endl;
		return Py_Ret(-1, "Failed to connect", -1);
	}
	freeaddrinfo(peer);

	FileRequest msg((char)GETDIR, my_email.c_str(), my_token.c_str(), "", "", "", 0);
	if (UDT::ERROR == UDT::send(fhandle, (char*)&msg, sizeof(msg), 0))
	{
		qDebug() << "send: " << UDT::getlasterror().getErrorMessage() << endl;
		return Py_Ret(-1, "Failed to send", -1);
	}
	int strLen = 0;
	if (UDT::ERROR == UDT::recv(fhandle, (char*)&strLen, sizeof(int), 0)) {
		qDebug() << "recv: " << UDT::getlasterror().getErrorMessage() << endl;
		return Py_Ret(-1, "Failed to get json len", -1);
	}
	qDebug() << "Strlen = " << strLen << endl;
	char* buff = new char[strLen + 1];
	if (UDT::ERROR == UDT::recv(fhandle, buff, strLen, 0)) {
		qDebug() << "recv: " << UDT::getlasterror().getErrorMessage() << endl;
		return Py_Ret(-1, "Failed to get json", -1);
	}
	buff[strLen] = '\0';
	//qDebug() << "str = " << buff << "*" << endl;
	UDT::close(fhandle);
	// use this function to release the UDT library
	return Py_Ret(0, buff, -1);
}

bool json_parse(const string& s, Json::Value& v) {
	Json::Reader reader;
	return reader.parse(s, v);
}

void json_write(string &s, Json::Value& v) {
	Json::FastWriter writer;
	s = writer.write(v);
}

void replace_cstr(string& str, char target, char r_char) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == target) str[i] = r_char;
	}
}

string&   replace_all(string&   str, const   string&   old_value, const   string&   new_value)
{
	while (true) {
		string::size_type   pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}

bool hasSuffix(const string & str, const string & substr)
{
	if (str.size() < substr.size()) return false;
	if (str.substr(str.size() - substr.size()) == substr) return true;
	return false;
}

string&   replace_all_distinct(string&   str, const   string&   old_value, const   string&   new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}

size_t get_file_size(const string& path) {
	QString pathname = QString::fromStdString(path);
	QFileInfo fileInfo(pathname);
	//---获取文件大小（字节）
	qint64 size = fileInfo.size();

	qDebug() << "Path" << path.c_str() << "size = " << size;
	return size;
}

string get_file_name(const string& path) {
	int off = -1;
	for (int i = path.size() - 1; i >= 0; --i) {
		if (path[i] == '/') {
			off = i + 1;
			break;
		}
	}
	if (off == -1) return path;
	return path.substr(off);
}


int my_sendfile(UDTSOCKET fhandle, fstream& ifs, size_t filesize) {
	char buffer[CHUNK_SIZE];
	while (filesize) {
		if (filesize >= CHUNK_SIZE) {
			ifs.read(buffer, CHUNK_SIZE);
			if (UDT::ERROR == UDT::send(fhandle, buffer, CHUNK_SIZE, 0)) {
				return -1;
			}
			filesize -= CHUNK_SIZE;
		}
		else {
			ifs.read(buffer, filesize);
			if (UDT::ERROR == UDT::send(fhandle, buffer, filesize, 0)) {
				return -1;
			}
			filesize -= filesize;
		}
	}
	return 0;
}

bool isDir(const char *lpPath) {
	QString pathname = QString::fromStdString(lpPath);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(pathname).data();
	struct stat s;
	stat(name.c_str(), &s);
	qDebug() << "Judge dir : " << name.c_str() << " " << (s.st_mode & S_IFDIR);
	return s.st_mode & S_IFDIR;
}

int API_TimeToString(string &strDateStr, const time_t &timeData)
{
	char chTmp[50];
	memset(chTmp, 0, sizeof(chTmp));
	struct tm *p;
	p = localtime(&timeData);
	p->tm_year = p->tm_year + 1900;
	p->tm_mon = p->tm_mon + 1;
	snprintf(chTmp, sizeof(chTmp), "%04d-%02d-%02d %02d:%02d:%02d",
		p->tm_year, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	strDateStr = chTmp;
	return 0;
}

int gSend(UDTSOCKET usock, const char* buf, int size, int) {
	int ssize = 0;
	int ss;
	while (ssize < size)
	{
		if (UDT::ERROR == (ss = UDT::send(usock, buf + ssize, size - ssize, 0)))
		{
			cout << "send:" << UDT::getlasterror().getErrorMessage() << endl;
			return UDT::ERROR;
		}

		ssize += ss;
	}
	return ssize;
}

int gRecv(UDTSOCKET usock, char * buf, int size, int)
{
	int rsize = 0;
	int rs;
	while (rsize < size)
	{
		if (UDT::ERROR == (rs = UDT::recv(usock, buf + rsize, size - rsize, 0))) {

			cout << "recv:" << UDT::getlasterror().getErrorMessage() << endl;
			return UDT::ERROR;
			break;
		}
		rsize += rs;
	}
	return rsize;
}

//从文件读入到string里

string readFileIntoString(const char * filename)
{
	string s;
	ifstream ifs(filename, ios::binary);
	if (ifs.is_open())
	{
		ifs.seekg(0, ios::beg);
		int len = ifs.tellg();
		ifs.seekg(0, ios::end);
		s.resize(len);
		ifs.read((char*)s.data(), len);
		ifs.close();
	}
	else
	{
		qDebug() << ("fopen error\n");
	}
	return s;
}

string hashFile(const char* filename) {
	QString pathname = QString::fromStdString(filename);
	QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
	std::string name = code->fromUnicode(pathname).data();
	string s;
	ifstream ifs(name.c_str(), ios::binary);
	MD5 m;
	if (ifs.is_open())
	{
		const int buffer_size = 8192;
		char* buffer = new char [buffer_size];
		while (ifs.read(buffer, buffer_size))
		{
			m.update(buffer, buffer_size);
		}
		int remain = ifs.gcount();
		if (remain) {
			m.update(buffer, remain);
		}
		delete[] buffer;
	}
	else
	{
		qDebug() << "fopen error\n";
	}
	//qDebug() << "fileStr: " << s.c_str() << s.size() << endl;
	
	return m.finalize().hexdigest();
}
