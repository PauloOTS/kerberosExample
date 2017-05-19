#include "kerbcrypto.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>

namespace KerbCrypto
{

	void generateRandomKey(byte* randomKey){
		srand(time(NULL));
		for (int i =0; i < 16; i++){
			randomKey[i] = rand()%128;
		}
	}

	void generateRandomIV(byte* randomIV){

		srand(time(NULL));
		for (int i =0; i < 16; i++){
			randomIV[i] = rand()%128;
		}
	}

	void encrypt(byte* output, QByteArray plaintext, int messageLen, byte* key, byte* iv){
		auto enc = new CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH, iv, 1);
		enc->ProcessData(output, (byte*)plaintext.data(), messageLen);

	}

	void decrypt(QByteArray& output, byte* ciphertext, int messageLen, byte* key, byte* iv){
		auto dec = new CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH, iv, 1);
		byte* plain = (byte*) malloc(sizeof(byte)*messageLen);
		dec->ProcessData(plain, ciphertext, messageLen);
		QByteArray plaintext((char*)plain, messageLen);
		output = plaintext;
	}

	QString base64encode(byte* array){
		std::string encoded;

		CryptoPP::StringSource ss(array, strlen((char*) array), true,
		    new CryptoPP::Base64Encoder(
			new CryptoPP::StringSink(encoded)
		    ) // Base64Encoder
		); // StringSourc

		QString result;
		result = QString::fromStdString(encoded);
		return result;
	}

	void base64decode(QString text, byte* output){
		std::string s = text.toUtf8().constData();
		std::string decoded;

		CryptoPP::StringSource ss(s, true,
		    new CryptoPP::Base64Decoder(
			new CryptoPP::StringSink(decoded)
		    ) // Base64Decoder
		); // StringSource

		char* aux = (char*) decoded.c_str();
		for (int i = 0; i < decoded.size(); i++)
			output[i] = (byte) aux[i];
	}
}
