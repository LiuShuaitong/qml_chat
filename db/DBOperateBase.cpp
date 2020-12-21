#include "DBOperateBase.h"
#include <QDir>

DBOperateBase::DBOperateBase(QObject *parent) : QObject(parent)
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        //建立和sqlite数据的连接
        _db = QSqlDatabase::addDatabase("QSQLITE");
        //设置数据库文件的名字
        QString dbname = QDir::currentPath() +QString("/")+ QString("chat.db");
        _db.setDatabaseName(dbname);
    }
}

bool DBOperateBase::openDB()
{
    if(_db.isOpen()){
        return true;
    }

    //打开数据库
    if(_db.open() == false){
        qDebug() << "连接数据失败！";
        return false;
    }
    qDebug() << "连接数据库成功";
    return true;
}

void DBOperateBase::closeDB()
{
    _db.close();
}
