#ifndef REQUESTTICKETAS_H
#define REQUESTTICKETAS_H
#include <QJsonObject>
#include "kerbcrypto.h"
#include <QJsonDocument>

class RequestASConfidentialInfo
{
public:
	RequestASConfidentialInfo();
	RequestASConfidentialInfo(int service_id, int time_sec);
	void encrypt(byte* output, byte* key, byte* iv);
	void decrypt(byte* info, int size, byte* key, byte* iv);
	bool read(const QJsonObject &json);
	bool write(QJsonObject &json);
private:
	int service_id;
	int time_sec;
	int random_number;
};


class RequestTicketAS
{
public:
	RequestTicketAS(int client_id, const RequestASConfidentialInfo& info);
	bool read(const QJsonObject &json, byte* key);
	bool write(QJsonObject &json, byte* key);

	RequestASConfidentialInfo getConfidential_info() const;
	void setConfidential_info(const RequestASConfidentialInfo &value);

private:
	const static QString IDENTIFIER;
	int client_ID;
	RequestASConfidentialInfo confidential_info;
	byte* iv;
};

#endif // REQUESTTICKETAS_H
