#ifndef CHATUSERMANAGER_H
#define CHATUSERMANAGER_H

#include <QObject>
#include "model/ChatUserModel.h"
#include "db/ChatUserDBOperate.h"
#include <QQmlApplicationEngine>

class ChatUserManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatUserManager(QObject *parent = nullptr);
    ~ChatUserManager();


    void createDB();

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

    /**
     * @brief loadChatListData      加载数据
     */
    void loadChatListData();

signals:

    /**
     * @brief nameChanged
     * @param name
     */
    void nameChanged(const QString name);

    /**
     * @brief sig_chatUserClick     点击用户列表
     * @param id                    用户id
     */
    void sig_chatUserClick(const QString &id);

public slots:

    /**
     * @brief on_addChatMsg         增加文本信息
     * @param userid                用户id
     * @param msg                   消息
     * @param time                  消息时间
     */
    void on_addChatMsg(const QString &userid,const QString &msg,const QString &time);
private:
    bool _isConnectSql{false};
    QString _name;
    QObject             *_root{nullptr};
    ChatUserModel       *_model{nullptr};
    ChatUserDBOperate   *_sqlOperator{nullptr};
};

#endif // CHATUSERMANAGER_H
