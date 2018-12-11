#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <qdebug.h>
#include "stdlib.h"
#include <direct.h>
#include <qfiledialog.h>
#include <qsettings.h>
#include <functional>
#include <QTextCodec>
#include <sys/stat.h>
#include "udt.h"
#include "md5.h"
using namespace std;
#pragma execution_character_set("utf-8")

#define SERVER_IP "114.67.37.2"
//#define SERVER_IP "192.168.135.131"
#define SERVER_PORT "20574"

#define getIconByIndex(index) QApplication::style()->standardIcon((enum QStyle::StandardPixmap)index)

#define ZERO(x) {memset((x), 0, sizeof(x));}

#define OP_TYPE int

//extern QSettings* setting;

enum OP {
	GETDIR, 
	UPLOAD,
	DOWNLOAD,
	DEL,
};

enum FILE_TRANS_ERROR {
	MY_NO_ERROR = 0,
	MY_ERROR,
	TOKEN_EXPIRE,
	FILE_EXISTS,
	FILE_NOT_EXISTS,
	SERVER_INTERNAL_ERROR,
	FILE_NAME_DULPLICTAION,
	FILE_OPEN_FAILED,
	INCORRECT_ADDR,
	CONNECT_FAILED,
	SEND_REQ_FAILED,
	RECV_REPLY_FAILED,
	REPLY_ERROR,
	STOP_BY_USER,
	RECV_FILE_ERROR,
	SEND_FILE_ERROR,
	USER_AUTH_FAILED,
	FILE_HASH_FAULT,
};

enum PROJ_TYPE {
	NO_TYPE = -1,
	PROTEIN = 0,
	DRUG,
	ANIMAL,
	METABOLOMICS,
};

extern const string ERROR_STR[];
extern const string TYPE[];

#define File_Container vector<MyFile>
#define Proj_Container vector<Proj*>

extern string			my_token;
extern string			my_email;
extern int				my_uid;
extern const string		WEB_SERVER_IP, WEB_SERVER_PORT;
extern const string		FILE_SERVER_IP, FILE_SERVER_PORT;

const int CHUNK_SIZE = 1 * 1 << 10;

struct Py_Ret {
	int status;
	string str;
	int extra;
	Py_Ret(int status, const string& str, int extra) : status(status), str(str), extra(extra) {}
	Py_Ret() { status = -1, str = "Error", extra = -1; }
	Py_Ret(const Py_Ret& ano) {
		status = ano.status;
		str = ano.str;
		extra = ano.extra;
	}
};

struct MyFile {
	bool isDir;
	int typeId;
	string projname;
	string filename;
	size_t filesize;
	time_t uploadtime;
	string email;
	string path;
	string fileHash;
	bool isDrive;
	int extra;
	MyFile(bool isDir, int typeId, const string& projname, const string& filename, size_t filesize, time_t uploadtime, string email, string path, string fileHash, bool isDrive=false)
		: isDir(isDir), typeId(typeId), projname(projname), filename(filename), filesize(filesize), uploadtime(uploadtime), email(email), 
		path(path), fileHash(fileHash), isDrive(isDrive) {
		//qDebug() << path.c_str() << "New Hash = " << fileHash.c_str();
		extra = 0;
		if (my_email == email) extra = 1;
	}

	MyFile() {}

	MyFile(const MyFile& ano) {
		isDir = ano.isDir;
		projname = ano.projname;
		filename = ano.filename;
		filesize = ano.filesize;
		uploadtime = ano.uploadtime;
		email = ano.email;
		path = ano.path;
		fileHash = ano.fileHash;
		isDrive = ano.isDrive;
		typeId = ano.typeId;
		extra = ano.extra;
	}

	bool valid() {
		return !projname.empty();
	}

	friend ostream& operator<<(ostream& os, const MyFile& ano) {
		if (ano.projname.empty()) os << "Invalid file";
		else os << ano.projname << " " << ano.filename << " " << ano.filesize << " " << ano.uploadtime << " " << ano.email;
		return os;
	}
};

struct FileRequest {
	char op;
	char email[50];
	char token[50];
	char type[50];
	char project_name[50];
	char file_name[100];
	size_t file_size;
	size_t offset;
	char fileHash[130];
	FileRequest() {
		ZERO(this->email); ZERO(this->token); ZERO(this->project_name); ZERO(this->file_name); ZERO(this->type);
	}
	FileRequest(char op, const char* email, const char* token, const char* type, const char* project_name, const char* file_name, size_t file_size, const char* fileHash = nullptr, size_t offset = 0) {
		this->op = op;
		this->file_size = file_size;
		this->offset = offset;
		memset((char*)this->fileHash, 0, sizeof(this->fileHash));
		ZERO(this->email); ZERO(this->token); ZERO(this->project_name); ZERO(this->file_name); ZERO(this->type); ZERO(this->fileHash);
		memcpy(this->email, email, strlen(email));
		memcpy(this->token, token, strlen(token));
		memcpy(this->type, type, strlen(type));
		memcpy(this->project_name, project_name, strlen(project_name));
		memcpy(this->file_name, file_name, strlen(file_name));
		if (fileHash != nullptr) memcpy(this->fileHash, fileHash, strlen(fileHash));
	}
};

struct FileReply {
	char op;
	char error_flag;
	size_t file_size;	//上传文件时0表示新文件，>0表示断点续传
	size_t offset;
	char fileHash[130];
	char extra[100];
};

struct Proj {
	string name;
	int uid;
	int typeId;
	File_Container files;
};

bool json_parse(const string& s, Json::Value& v);

void json_write(string &s, Json::Value& v);

void replace_cstr(string& str, char target, char r_char);

string&   replace_all_distinct(string&   str, const   string&   old_value, const   string&   new_value);

string&   replace_all(string&   str, const   string&   old_value, const   string&   new_value);

bool hasSuffix(const string& str, const string& substr);

size_t get_file_size(const string& path);

string get_file_name(const string& path);

Py_Ret login(const string& email, const string& password);

Py_Ret get_all_project(const string& email, const string& token);

int my_sendfile(UDTSOCKET fhandle, fstream& ifs, size_t filesize);

string browse_file();

bool compareIgnoreCase(const string& s1, const string& s2);

bool isDir(const char *lpPath);

int API_TimeToString(string &strDateStr, const time_t &timeData);

int gSend(UDTSOCKET usock, const char* buf, int size, int);

int gRecv(UDTSOCKET usock, char* buf, int size, int);

string readFileIntoString(const char * filename);

string hashFile(const char* filename);
#endif // !UTIL_H