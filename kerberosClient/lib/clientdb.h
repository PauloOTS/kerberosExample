#ifndef CLIENTBD_H
#define CLIENTBD_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <memory>
#include <cassert>


/**
 * @brief Function to check if a certain file exists given a path
 * @param path Path to the file
 * @return Boolean True for exists and 0 otherwhise
 */
bool fileExists(QString path);

/**
 * @brief The class to abstract client access to the database
 */
class ClientDB
{
public:
	ClientDB(const QString& path);
	QString getPassword(const QString& user);
	QSqlError addNewUser(const QString& password, const QString& name);
	~ClientDB();

private:
	/**
	 * @brief Function to initialize the database
	 * @return Error in database, if so
	 */
	QSqlError init();
	/**
	 * @brief Function to create the database
	 * @return Error, if so
	 */
	QSqlError createNewDB();
	/**
	 * @brief Path to the database
	 */
	QString path;
	/**
	 * @brief Pointer to the database
	 */
	std::unique_ptr<QSqlDatabase> db;
};
#endif // CLIENTBD_H
