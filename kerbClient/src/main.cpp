#include "login.h"
#include <QApplication>
#include <QDebug>
#include "kerbcrypto.h"
#include "requestticketas.h"

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//Login w;
	//w.show();

	QString string;

	byte* key = (byte*) malloc (sizeof(byte)*16);

	KerbCrypto::generateRandomKey(key);

	QJsonObject jinfo;
	RequestASConfidentialInfo info(2, 100);
	info.write(jinfo);
	QJsonDocument jdoc1(jinfo);


	qDebug() << jdoc1.toJson(QJsonDocument::Indented);

	RequestTicketAS request(22, info);

	QJsonObject jrequest;
	request.write(jrequest, key);

	QJsonDocument j2(jrequest);

	request.read(jrequest, key);
	request.getConfidential_info().write(jinfo);
	jdoc1.setObject(jinfo);
	qDebug() << jdoc1.toJson(QJsonDocument::Indented);

	//return a.exec();
}
