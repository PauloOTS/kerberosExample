#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "clientdb.h"
#include "kerberosclient.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
	Q_OBJECT

public:
	explicit Login(QWidget *parent = 0);
	~Login();

private:
	Ui::Login *ui;
	std::unique_ptr<ClientDB> db;
	KerberosClient client;

private slots:
	void on_loginButton_released();
	void on_cadastroButton_released();
};

#endif // LOGIN_H
