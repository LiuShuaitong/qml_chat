#include "ChatRecordModel.h"

ChatRecordModel::ChatRecordModel(QObject *parent) : QAbstractListModel(parent)
{

}

ChatRecordModel::~ChatRecordModel()
{

}

int ChatRecordModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _dataList.count();
}

QVariant ChatRecordModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >= _dataList.count()) {
        return QVariant();
    }

    const ChatRecordListData &data = _dataList[row];
    switch (role) {
    case IDRole:
        return data.id();
    case USERIDRole:
        return data.userid();
    case SENDERRole:
        return data.sender();
    case TYPERole:
        return data.type();
    case TIMERole:
        return data.time();
    case MSGRole:
        return data.msg();
    }
    return QVariant();
}

void ChatRecordModel::insert(int index, const ChatRecordListData &data)
{
    if(index < 0 || index > _dataList.count()) {
        return;
    }
    emit beginInsertRows(QModelIndex(), index, index);
    _dataList.insert(index, data);
    emit endInsertRows();
}

void ChatRecordModel::append(const qint64 &id, const QString &userid, const bool &sender, const QString &time, const QString &msg, ChatRecordListData::MsgType type)
{
    insert(count(), ChatRecordListData(id,userid,sender,time,msg,type));
}

void ChatRecordModel::remove(int index)
{
    if(index < 0 || index >= _dataList.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    _dataList.removeAt(index);
    endRemoveRows();
}

int ChatRecordModel::count()
{
    return rowCount(QModelIndex());
}

void ChatRecordModel::clear()
{
    while (_dataList.size() > 0)
    {
        remove(0);
    }
}

QHash<int, QByteArray> ChatRecordModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IDRole]       = "mdId";
    roles[USERIDRole]   = "mdUserId";
    roles[SENDERRole]   = "mdSender";
    roles[TYPERole]     = "mdType";
    roles[TIMERole]     = "mdTime";
    roles[MSGRole]      = "mdMsg";
    return roles;
}

