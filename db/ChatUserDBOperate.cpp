#include "ChatUserDBOperate.h"

ChatUserDBOperate::ChatUserDBOperate(QObject *parent) : QObject(parent)
{
}

ChatUserDBOperate::~ChatUserDBOperate()
{
}

void ChatUserDBOperate::createTab()
{
    //用于执行sql语句的对象
    QSqlQuery sql_query;
    QString create_sql = QString("create table chatlist ("
                          "id text primary key NOT NULL,"
                          "name text NOT NULL,"
                          "time text NOT NULL,"
                          "msg text NOT NULL)");

    if(!sql_query.exec(create_sql))
    {
        qDebug() << __func__ << sql_query.lastError();
    }
    else
    {
        qDebug() << __func__ << "create chatlist success";
    }
}

QList<ChatUserListData> ChatUserDBOperate::queryTabData(const QString &name)
{
    QSqlQuery sql_query;
    QString select_sql;
    select_sql = name.isEmpty() ? "select * from chatlist" :
                                  "select * from chatlist where name like '%" + name + "%'";
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        QList<ChatUserListData> list;
        while(sql_query.next())
        {
            QString id = sql_query.value(0).toString();
            QString name = sql_query.value(1).toString();
            QString time = sql_query.value(2).toString();
            QString msg = sql_query.value(3).toString();
            list.push_back(ChatUserListData(id,name,time,msg));
            qDebug()<<QString("id:%1 , name:%2 ,tiem:%3 ,msg:%4").arg(id).arg(name).arg(time).arg(msg);
        }
        return list;
    }
    return QList<ChatUserListData>();
}

void ChatUserDBOperate::updateTabData(const ChatUserListData &data)
{
    QSqlQuery sql_query;

    QString insert_sql = QString("update chatlist set name = '%1',time = '%2',msg = '%3' where id = '%4'")
            .arg(data.name()).arg(data.time()).arg(data.msg()).arg(data.id());
    if(!sql_query.exec(insert_sql))
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "update " << data.name() << data.time() << data.msg() << data.id();
    }
}

void ChatUserDBOperate::insertTabData(const ChatUserListData &data)
{
    //用于执行sql语句的对象
    QSqlQuery sql_query;
    QString insert_sql = "insert into chatlist values (?, ?, ? ,?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(data.id());
    sql_query.addBindValue(data.name());
    sql_query.addBindValue(data.time());
    sql_query.addBindValue(data.msg());
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted " << data.name();
    }
}

void ChatUserDBOperate::deleteTabData(QString &id)
{
    QSqlQuery query;
    QString insert_sql = "delete from chatlist where id = ?";
    query.prepare(insert_sql);
    query.addBindValue(id);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"deleted!";
    }
}

bool ChatUserDBOperate::IsTabExists(QString tabName)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.tables().contains(tabName))
    {
        return true;
    }
    return false;
}

