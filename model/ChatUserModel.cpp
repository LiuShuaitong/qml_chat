#include "ChatUserModel.h"
#include <QDebug>

ChatUserModel::ChatUserModel(QObject *parent):
    QAbstractListModel(parent)
{
}

ChatUserModel::~ChatUserModel()
{
}

int ChatUserModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _dataList.count();
}

QVariant ChatUserModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >= _dataList.count()) {
        return QVariant();
    }

    const ChatUserListData &data = _dataList[row];
    switch (role) {
    case IDRole:
        return data.id();
    case NAMERole:
        return data.name();
    case TIMERole:
        return data.time();
    case MSGRole:
        return data.msg();
    }

    return QVariant();
}

void ChatUserModel::insert(int index, const ChatUserListData &data)
{
    if(index < 0 || index > _dataList.count()) {
        return;
    }
    emit beginInsertRows(QModelIndex(), index, index);
    _dataList.insert(index, data);
    emit endInsertRows();
}

void ChatUserModel::remove(int index)
{
    if(index < 0 || index >= _dataList.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    _dataList.removeAt(index);
    endRemoveRows();
}

void ChatUserModel::append(const QString &id, const QString &name, const QString &time, const QString &msg)
{
    insert(count(), ChatUserListData(id,name,time,msg));
}

ChatUserListData ChatUserModel::update(const QString &userid, const QString &msg,const QString &time)
{
    for(int i=0;i<_dataList.size();i++)
    {
        if(_dataList.at(i).id() == userid)
        {
            beginResetModel();
            ChatUserListData data = _dataList.at(i);
            data.setTime(time);
            data.setMsg(msg);
            _dataList.replace(i,data);
            endResetModel();
            return data;
        }
    }
    return ChatUserListData("","","","");
}

int ChatUserModel::count()
{
    return rowCount(QModelIndex());
}

void ChatUserModel::clear()
{
    while (_dataList.size() > 0)
    {
        remove(0);
    }
}

QHash<int, QByteArray> ChatUserModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IDRole] = "mdId";
    roles[NAMERole] = "mdName";
    roles[TIMERole] = "mdTime";
    roles[MSGRole] = "mdMsg";
    return roles;
}
