
#include "HttpConnect.h"
#include "util.h"
#pragma comment(lib,"ws2_32.lib")

HttpConnect::HttpConnect(string port)
{
	this->port = atoi(port.c_str());
	//�˴�һ��Ҫ��ʼ��һ�£�����gethostbyname����һֱΪ��
	WSADATA wsa = { 0 };
	WSAStartup(MAKEWORD(2, 2), &wsa);
	reply = new char[1024 * 1024];
}

HttpConnect::~HttpConnect()
{
	delete[] reply;
}

int HttpConnect::socketHttp(string host, string request) {
	qDebug() << host.c_str() << request.c_str();
	int sockfd;
	struct sockaddr_in address;
	struct hostent *server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	server = gethostbyname(host.c_str());
	memcpy((char *)&address.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
	if (-1 == connect(sockfd, (struct sockaddr *)&address, sizeof(address))) {
		qDebug() << "connection error!";
		return -1;
	}

	//qDebug() << request.c_str();
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)new int(5000), sizeof(int));
	setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)new int(5000), sizeof(int));
	send(sockfd, request.c_str(), request.size(), 0);
	memset(reply, 0, 1024 * 1024);
	int offset = 0;
	int rc;
	while (rc = recv(sockfd, reply + offset, 1024, 0)) {
		offset += rc;
	}
	if (rc == -1) return -1;
	closesocket(sockfd);
	reply[offset] = 0;
	return 0;
	//qDebug() << reply;
}



string HttpConnect::postData(std::string host, std::string path, std::string post_content)
{
	//POST����ʽ

	std::stringstream stream;

	stream << "POST " << path;

	stream << " HTTP/1.0\r\n";

	stream << "Host: " << host << "\r\n";

	stream << "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.3) Gecko/20100401 Firefox/3.6.3\r\n";

	stream << "Content-Type:application/x-www-form-urlencoded\r\n";

	stream << "Content-Length:" << post_content.length() << "\r\n";

	stream << "Connection:close\r\n\r\n";
	stream << post_content.c_str();
	if (socketHttp(host, stream.str()) == 0) {
		return reply;
	}
	else {
		return "";
	}
}



string HttpConnect::getData(std::string host, std::string path, std::string get_content)
{
	//GET����ʽ

	std::stringstream stream;

	stream << "GET " << path << "?" << get_content;

	stream << " HTTP/1.1\r\n";

	stream << "Host: " << host << "\r\n";

	stream << "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.3) Gecko/20100401 Firefox/3.6.3\r\n";

	stream << "Connection:close\r\n\r\n";

	qDebug() << host.c_str() << stream.str().c_str();

	if (socketHttp(host, stream.str()) == 0) {
		return reply;
	}
	else {
		return "";
	}
}
