#include "kerberosclient.h"
#include "ui_kerberosclient.h"

KerberosClient::KerberosClient(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::KerberosClient)
{
	ui->setupUi(this);
}

KerberosClient::~KerberosClient()
{
	delete ui;
}
