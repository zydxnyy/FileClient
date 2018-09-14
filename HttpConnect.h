#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <qdebug.h>
#include <sstream>
using namespace std;

class HttpConnect
{
	char* reply;
	int port;
public:

	HttpConnect(int port);
	void HttpConnect::socketHttp(string host, string request);
	string HttpConnect::postData(std::string host, std::string path, std::string post_content);
	string HttpConnect::getData(std::string host, std::string path, std::string get_content);

	~HttpConnect();
};

