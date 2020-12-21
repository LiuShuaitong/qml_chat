#include "ChatUserListData.h"

ChatUserListData::ChatUserListData(const QString &id, const QString &name, const QString &time, const QString &msg) :
    _id(id),
    _name(name),
    _time(time),
    _msg(msg)
{}

QString ChatUserListData::name() const
{
    return _name;
}

QString ChatUserListData::id() const
{
    return _id;
}

QString ChatUserListData::time() const
{
    return _time;
}

QString ChatUserListData::msg() const
{
    return _msg;
}

void ChatUserListData::setMsg(const QString &msg)
{
    _msg = msg;
}

void ChatUserListData::setTime(const QString &time)
{
    _time = time;
}
