#ifndef CHARRECORDMANAGER_H
#define CHARRECORDMANAGER_H

#include <QObject>
#include "db/ChatRecordDBOperate.h"
#include "model/ChatRecordModel.h"
#include <QQmlApplicationEngine>

class CharRecordManager : public QObject
{
    Q_OBJECT
public:
    explicit CharRecordManager(QObject *parent = nullptr);
    ~CharRecordManager();

    /**
     * @brief registQMLEngine       注册QML事件
     * @param engine
     */
    void registQMLEngine(const QQmlApplicationEngine &engine);

    void registQMLObject(QObject *object);

    void createDB();

    /**
     * @brief search                QML回调查找用户
     * @param msg
     */
    Q_INVOKABLE void send(const QString &msg);

signals:

    /**
     * @brief sig_addChatMsg        通知用户聊天列表，发送文本消息，更新消息
     * @param userid                用户id
     * @param msg                   消息
     * @param tiem                  消息时间
     */
    void sig_addChatMsg(const QString &userid,const QString &msg,const QString &time);

public slots:

    /**
     * @brief on_chatUserClick      点击用户聊天列表用户
     * @param id                    用户id
     */
    void on_chatUserClick(const QString &id);

private:
    bool _isConnectSql{false};
    QString             _userId;
    QObject             *_root{nullptr};
    ChatRecordModel     *_model{nullptr};
    ChatRecordDBOperate *_db{nullptr};
};

#endif // CHARRECORDMANAGER_H
