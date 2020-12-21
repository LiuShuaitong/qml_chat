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
private:
    QString _id;
    QString _name;
    QString _time;
    QString _msg;
};

#endif // CHATUSERLISTDATA_H
