#ifndef CHATRECORDMODEL_H
#define CHATRECORDMODEL_H

#include "data/ChatRecordListData.h"
#include <QAbstractListModel>

class ChatRecordModel : public QAbstractListModel
{
    Q_OBJECT
public:

    /**
     * @brief The DataRoles enum        自定义类型
     */
    enum DataRoles
    {
        IDRole = Qt::UserRole + 1,
        USERIDRole,
        SENDERRole,
        TIMERole,
        TYPERole,
        MSGRole
    };

    explicit ChatRecordModel(QObject *parent = nullptr);
    ~ChatRecordModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int count();
    void clear();
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void insert(int index,const ChatRecordListData &data) ;
    Q_INVOKABLE void append(const qint64 &id,const QString &userid,const bool &sender,const QString &time,const QString &msg,ChatRecordListData::MsgType type);

protected:
    virtual QHash<int, QByteArray> roleNames() const override;
private:
    QList<ChatRecordListData> _dataList;

};

#endif // CHATRECORDMODEL_H
