#include "kerberosclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KerberosClient w;
	w.show();

	return a.exec();
}
