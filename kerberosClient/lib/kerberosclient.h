#ifndef KERBEROSCLIENT_H
#define KERBEROSCLIENT_H

#include <QMainWindow>
#include "clientdb.h"

namespace Ui {
class KerberosClient;
}

class KerberosClient : public QMainWindow
{
	Q_OBJECT

public:
	explicit KerberosClient(QWidget *parent = 0);
	~KerberosClient();

private:
	Ui::KerberosClient *ui;
};

#endif // KERBEROSCLIENT_H
