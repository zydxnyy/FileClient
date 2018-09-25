#include "FileClient.h"
#include <QtWidgets/QApplication>
#include <qnetwork.h>
#include <json/json.h>
#include <qhash.h>
#include <qdebug.h>
#include <curl/curl.h>
#include <qsettings.h>
#include "LocalExplorer.h"
#include "Login.h"
#include "HttpOp.h"
#include "HttpConnect.h"
#ifdef QT_NO_DEBUG
	#pragma comment(lib, "lib_json.lib")
	#pragma comment(lib, "udt.lib")
#else
	#pragma comment(lib, "lib_jsond.lib")
	#pragma comment(lib, "udtd.lib")
#endif
#pragma comment(lib,"ws2_32.lib")
#pragma execution_character_set("utf-8")


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<Py_Ret>("Py_Ret");
	UDT::startup();

	Login login;
	if (login.exec() != QDialog::Accepted) return 0;

	FileClient w;
	w.show();
	a.exec();
	UDT::cleanup();

	return 0;
}

