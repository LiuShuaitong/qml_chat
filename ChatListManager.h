#ifndef CHATLISTMANAGER_H
#define CHATLISTMANAGER_H

#include <QObject>
#include "ChatListModel.h"
#include "ChatUserDBOperate.h"
#include <QQmlApplicationEngine>

class ChatListManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatListManager(QObject *parent = nullptr);
    ~ChatListManager();

    /**
     * @brief registQMLEngine       注册QML事件
     * @param engine
     */
    void registQMLEngine(const QQmlApplicationEngine &engine);

    void registQMLObject(QObject *object);

    /**
     * @brief search                QML回调查找用户
     * @param name
     */
    Q_INVOKABLE void search(const QString &name);

    /**
     * @brief clickChatList         QML回调当前index
     * @param index
     */
    Q_INVOKABLE void clickChatList(int index);

    // 注册属性，使之可以在QML中调用
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
    void setName(const QString &name);
    QString getName() const;

signals:
    void nameChanged(const QString name);
private:
    /**
     * @brief loadChatListData      加载数据
     */
    void loadChatListData();
private:
    bool _isConnectSql{false};
    QString _name;
    QObject             *_root{nullptr};
    ChatListModel       *_model{nullptr};
    ChatUserDBOperate   *_sqlOperator{nullptr};
};

#endif // CHATLISTMANAGER_H
