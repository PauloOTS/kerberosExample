#ifndef KERBCRYPTO_H
#define KERBCRYPTO_H
#include "crypto++/aes.h"
#include "crypto++/filters.h"
#include "crypto++/modes.h"
#include "crypto++/base64.h"
#include <QString>
#include <iomanip>

namespace KerbCrypto
{
	void generateRandomKey(byte* randomKey);
	void generateRandomIV(byte* randomIV);
	void encrypt(byte* output, QByteArray plaintext, int messageLen, byte* key, byte* iv);
	void decrypt(QByteArray& output, byte* ciphertext, int messageLen, byte* key, byte* iv);
	QString base64encode(byte* array);
	void base64decode(QString text, byte* output);
};

#endif // KERBCRYPTO_H
