#ifndef CHATUSERLISTDATA_H
#define CHATUSERLISTDATA_H

#include <QString>

class ChatUserListData
{
public:
    ChatUserListData(const QString &id,const QString &name,const QString &time,const QString &msg);
    QString name() const;
    QString id() const;
    QString time() const;
    QString msg() const;

    void setMsg(const QString &msg);
    void setTime(const QString &time);
public:
    QString _id;
    QString _name;
    QString _time;
    QString _msg;
};

#endif // CHATUSERLISTDATA_H
