#include "requestticketas.h"
#include <QDebug>

RequestASConfidentialInfo::RequestASConfidentialInfo(){

}

RequestASConfidentialInfo::RequestASConfidentialInfo(int service_id, int time_sec){
	srand(time(NULL));
	this->service_id = service_id;
	this->time_sec = time_sec;
	this->random_number = rand()%1000000;
}

bool RequestASConfidentialInfo::write(QJsonObject &json){
	json["service_id"] = service_id;
	json["time"] = time_sec;
	json["random_number"] = random_number;

	return true;
}

bool RequestASConfidentialInfo::read(const QJsonObject &json){
	this->service_id = json["service_id"].toInt();
	this->time_sec = json["time"].toInt();
	this->random_number = json["random_number"].toInt();

	return true;
}

void RequestASConfidentialInfo::encrypt(byte* output, byte *key, byte *iv){
	QJsonObject json;
	this->write(json);
	QJsonDocument jdoc(json);
	QByteArray temp = jdoc.toBinaryData();
	//qDebug() << "Primeiro binary" << temp.data();
	KerbCrypto::encrypt(output, temp, temp.size(), key, iv);
}

void RequestASConfidentialInfo::decrypt(byte* info, int size, byte *key, byte *iv){
	QByteArray temp;
	KerbCrypto::decrypt(temp, info, size, key, iv);
	QJsonDocument jdoc = QJsonDocument::fromBinaryData(temp);
	QJsonObject j = jdoc.object();
	qDebug() << jdoc.toJson(QJsonDocument::Indented);
	this->read(j);
}

const QString RequestTicketAS::IDENTIFIER = "request_as";

RequestTicketAS::RequestTicketAS(int client_id, const RequestASConfidentialInfo &info){
	this->client_ID = client_id;
	this->confidential_info = info;
	this->iv = (byte*) malloc(sizeof(byte)*16);
	KerbCrypto::generateRandomIV(iv);
}

bool RequestTicketAS::read(const QJsonObject &json, byte* key){
	qDebug() << "Read 1";
	if (json["ident"].toString() != RequestTicketAS::IDENTIFIER)
		return false;

	this->client_ID = json["client_id"].toInt();

	QString temp = json["iv"].toString();
	KerbCrypto::base64decode(temp, this->iv);
	temp = json["confidential"].toString();
	byte* output = (byte*) malloc(sizeof(byte)*temp.size());


	KerbCrypto::base64decode(temp, output);


	this->confidential_info.decrypt(output, temp.size(), key, this->iv);


	qDebug() << "Read 2";
	return true;
}

bool RequestTicketAS::write(QJsonObject &json, byte* key){

	qDebug() << "Write 1";
	json["ident"] = RequestTicketAS::IDENTIFIER;
	json["client_id"] = this->client_ID;

//	QJsonObject jConfidential;
//	if (!this->confidential_info.write(jConfidential))
//		return false;

	json["iv"] = KerbCrypto::base64encode(this->iv);
	QJsonObject j;
	this->confidential_info.write(j);
	QJsonDocument jdoc(j);
	byte* output = (byte*) malloc (sizeof(byte)*jdoc.toBinaryData().size());
	this->confidential_info.encrypt(output, key, this->iv);
	json["confidential"] = KerbCrypto::base64encode(output);

	qDebug() << "Write 2";
	return true;
}

RequestASConfidentialInfo RequestTicketAS::getConfidential_info() const
{
	return confidential_info;
}

void RequestTicketAS::setConfidential_info(const RequestASConfidentialInfo &value)
{
	confidential_info = value;
}
