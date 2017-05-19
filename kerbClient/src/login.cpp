#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Login)
{
	ui->setupUi(this);
	std::unique_ptr<ClientDB> new_db(
				new ClientDB("db.sqlite"));

	db = std::move(new_db);
}

Login::~Login()
{
	delete ui;
}

void Login::on_loginButton_released()
{
	QString pass = db->getPassword(ui->userText->text().trimmed());
	if (QString::compare(ui->passTextField->text(), pass)){
		QMessageBox::critical(this, tr("Error"), tr("Wrong Password or Username"));
		return;
	}

	this->setVisible(false);
	client.show();

}

void Login::on_cadastroButton_released()
{
	db->addNewUser(ui->passTextField->text().trimmed(), ui->userText->text().trimmed());
	ui->passTextField->clear();
}
