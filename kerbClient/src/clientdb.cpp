#include "clientdb.h"

bool fileExists(QString path){
	QFileInfo info(path);
	return info.exists() && info.isFile();
}

ClientDB::ClientDB(const QString& path)
{
	this->path = path;
	std::unique_ptr<QSqlDatabase> new_db(
				new QSqlDatabase());

	db = std::move(new_db);

	init();
}

ClientDB::~ClientDB(){

}

QSqlError ClientDB::init(){
	bool fileExistance = fileExists(path);
	*db = QSqlDatabase::addDatabase("QSQLITE");
	db->setDatabaseName(path);

	if (!(db->open())){
		qDebug() << "Conexão com Database falhou.";
		return QSqlError();
	}

	else{
		qDebug() << "Conectado com o Database" << path;
		if (!(fileExistance)){
			qDebug() << "Criando um novo database para:" << path;
			this->createNewDB();
		}
	}

	return QSqlError();
}

QSqlError ClientDB::createNewDB(){

	QSqlQuery q(*db);
	if (!q.exec(QString("create table users(id integer primary key autoincrement,"
			    "name varchar(256), password varchar(256))")))
		return q.lastError();

	return QSqlError();
}


QSqlError ClientDB::addNewUser(const QString& password, const QString& name){
	QSqlQuery q(*db);
	q.prepare("INSERT INTO users(name, password) VALUES (:n, :p)");
	q.bindValue(":p", password.trimmed());
	q.bindValue(":n", name.trimmed());
	if (!q.exec())
		return q.lastError();

	return QSqlError();
}

QString ClientDB::getPassword(const QString& user){
	QSqlQuery q(*db);
	q.prepare("SELECT password FROM users WHERE name like :u");
	q.bindValue(":u", user);
	q.exec();
	QString result;
	if (q.next()){
		result = q.value(0).toString();
	}

	return result;
}
