#ifndef CHATRECORDLISTDATA_H
#define CHATRECORDLISTDATA_H

#include <QObject>

class ChatRecordListData
{
public:

    enum MsgType{
        Text,
        Image,
        Emoji
    };

    explicit ChatRecordListData(const qint64 &id,const QString &userid,const bool &sender,const QString &time,const QString &msg,MsgType type);

    qint64 id() const;
    QString userid() const;
    QString msg() const;
    QString time() const;
    bool sender() const;
    MsgType type() const;

private:
    qint64 _id;
    QString _userid;
    QString _msg;
    QString _time;
    // 是否是发送方
    bool _sender;
    MsgType _type;
};

#endif // CHATRECORDLISTDATA_H
