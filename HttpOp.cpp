#include "HttpOp.h"

Py_Ret verify_account(string email, string password) {
	HttpConnect* p = new HttpConnect(WEB_SERVER_PORT);
	string res = p->postData(WEB_SERVER_IP, "/api/verify_account/", "email="+email+"&password="+password);
	if (res.empty()) {
		return Py_Ret(-1, "服务器连接失败", -1);
	}
	res = res.substr(res.find("\r\n\r\n") + 4);
	Json::Value root;
	if (json_parse(res, root)) {
		if (root["error_msg"].isString()) {
			string error_msg = root["error_msg"].asString();
			return Py_Ret(-1, error_msg, -1);
		}
		else {
			string token = root["token"].asString();
			int uid = root["uid"].asUInt();
			return Py_Ret(0, token, uid);
		}
	}
	else return Py_Ret(-1, "Json parse failed", -1);
}

Py_Ret getAllProject(string email, string token) {
	HttpConnect* p = new HttpConnect(WEB_SERVER_PORT);
	string res = p->postData(WEB_SERVER_IP, "/api/get_all_project/", "email=" + email + "&token=" + token);
	if (res.empty()) {
		return Py_Ret(-1, "服务器连接失败", -1);
	}
	res = res.substr(res.find("\r\n\r\n") + 4);
	Json::Value root;
	if (json_parse(res, root)) {
		if (root["error_msg"].isString()) {
			string error_msg = root["error_msg"].asString();
			return Py_Ret(-1, error_msg, -1);
		}
		else {
			string projects = root["projects"].asString();
			return Py_Ret(0, projects, -1);
		}
	}
	else return Py_Ret(-1, "Json parse failed", -1);
}

int check_token(string email, string token) {

	HttpConnect* p = new HttpConnect(WEB_SERVER_PORT);
	string res = p->postData(WEB_SERVER_IP, "/api/check_token/", "email=" + email + "&token=" + token);
	if (res.empty()) {
		return -1;
	}
	res = res.substr(res.find("\r\n\r\n") + 4);
	int ret = atoi(res.c_str());
	return ret;
}