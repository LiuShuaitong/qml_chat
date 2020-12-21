#include "ChatRecordDBOperate.h"

ChatRecordDBOperate::ChatRecordDBOperate(QObject *parent) : QObject(parent)
{
}

ChatRecordDBOperate::~ChatRecordDBOperate()
{

}

void ChatRecordDBOperate::createTab()
{
    //用于执行sql语句的对象
    QSqlQuery sql_query;
    QString create_sql = QString("create table chatrecord ("
                                 "id integer primary key AUTOINCREMENT,"
                                 "userid text NOT NULL,"
                                 "sender int NOT NULL,"
                                 "time text NOT NULL,"
                                 "type int NOT NULL,"
                                 "msg text NOT NULL)");

    if(!sql_query.exec(create_sql))
    {
        qDebug() << __func__ << sql_query.lastError();
    }
    else
    {
        qDebug() << __func__ << "create chatrecord success";
    }
}

QList<ChatRecordListData> ChatRecordDBOperate::queryTabData(const QString &userid)
{
    QSqlQuery sql_query;
    QString select_sql = "select * from chatrecord where userid = '" + userid + "'";
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        QList<ChatRecordListData> list;
        while(sql_query.next())
        {
            qint64 id = sql_query.value(0).toULongLong();
            QString userid = sql_query.value(1).toString();
            bool sender = sql_query.value(2).toBool();
            QString time = sql_query.value(3).toString();
            int type = sql_query.value(4).toInt();
            QString msg = sql_query.value(5).toString();

            // ChatRecordListData(const qint64 &id,const QString &userid,const bool &sender,const QString &time,const QString &msg,MsgType type);
            list.push_back(ChatRecordListData(id,userid,sender,time,msg,(ChatRecordListData::MsgType)type));
            qDebug()<<QString("id:%1 , name:%2 ,tiem:%3 ,msg:%4").arg(id).arg(userid).arg(time).arg(msg);
        }
        return list;
    }
    return QList<ChatRecordListData>();
}

void ChatRecordDBOperate::insertTabData(const ChatRecordListData &data)
{
    //用于执行sql语句的对象
    QSqlQuery sql_query;
    QString insert_sql = "insert into chatrecord(userid,sender,time,type,msg) values (?, ?, ?, ? ,?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(data.userid());
    sql_query.addBindValue(int(data.sender()));
    sql_query.addBindValue(data.time());
    sql_query.addBindValue(int(data.type()));
    sql_query.addBindValue(data.msg());
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted " << data.userid();
    }

}

void ChatRecordDBOperate::deleteTabData(QString &id)
{
    QSqlQuery query;
    QString insert_sql = "delete from chatrecord where id = ?";
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

void ChatRecordDBOperate::deleteUserData(const QString &userid)
{
    QSqlQuery query;
    QString insert_sql = "delete from chatrecord where userid = ?";
    query.prepare(insert_sql);
    query.addBindValue(userid);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"deleted!";
    }
}

bool ChatRecordDBOperate::IsTabExists(QString tabName)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.tables().contains(tabName))
    {
        return true;
    }
    return false;
}
