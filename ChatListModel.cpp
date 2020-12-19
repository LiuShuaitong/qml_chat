#include "ChatListModel.h"
#include <QDebug>

ChatListModel::ChatListModel(QObject *parent):
    QAbstractListModel(parent)
{
}

ChatListModel::~ChatListModel()
{
}

int ChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _dataList.count();
}

QVariant ChatListModel::data(const QModelIndex &index, int role) const
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

void ChatListModel::insert(int index, const ChatUserListData &data)
{
    if(index < 0 || index > _dataList.count()) {
        return;
    }
    emit beginInsertRows(QModelIndex(), index, index);
    _dataList.insert(index, data);
    emit endInsertRows();
}

void ChatListModel::remove(int index)
{
    if(index < 0 || index >= _dataList.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    _dataList.removeAt(index);
    endRemoveRows();
}

void ChatListModel::append(const QString &id, const QString &name, const QString &time, const QString &msg)
{
    insert(count(), ChatUserListData(id,name,time,msg));
}

int ChatListModel::count()
{
    return rowCount(QModelIndex());
}

void ChatListModel::clear()
{
    while (_dataList.size() > 0)
    {
        remove(0);
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IDRole] = "mdId";
    roles[NAMERole] = "mdName";
    roles[TIMERole] = "mdTime";
    roles[MSGRole] = "mdMsg";
    return roles;
}

