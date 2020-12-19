#ifndef CHATLISTMODEL_H
#define CHATLISTMODEL_H

#include <ChatUserListData.h>
#include <QAbstractListModel>

class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    /**
     * @brief The DataRoles enum        自定义类型
     */
    enum DataRoles
    {
        IDRole = Qt::UserRole + 1,
        NAMERole,
        TIMERole,
        MSGRole
    };

    explicit ChatListModel(QObject *parent = nullptr);
    ~ChatListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int count();
    void clear();
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void insert(int index,const ChatUserListData &data) ;
    Q_INVOKABLE void append(const QString &id,const QString &name,const QString &time,const QString &msg);

protected:
    virtual QHash<int, QByteArray> roleNames() const override;
private:
    QList<ChatUserListData> _dataList;
};

#endif // CHATLISTMODEL_H
