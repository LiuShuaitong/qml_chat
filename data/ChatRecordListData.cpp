#include "ChatRecordListData.h"

ChatRecordListData::ChatRecordListData(const qint64 &id,const QString &userid,const bool &sender, const QString &time,const QString &msg, ChatRecordListData::MsgType type) :
    _id(id),
    _userid(userid),
    _msg(msg),
    _time(time),
    _sender(sender),
    _type(type)
{

}

qint64 ChatRecordListData::id() const
{
    return _id;
}

QString ChatRecordListData::userid() const
{
    return _userid;
}

QString ChatRecordListData::msg() const
{
    return _msg;
}

QString ChatRecordListData::time() const
{
    return _time;
}

bool ChatRecordListData::sender() const
{
    return _sender;
}

ChatRecordListData::MsgType ChatRecordListData::type() const
{
    return _type;
}
