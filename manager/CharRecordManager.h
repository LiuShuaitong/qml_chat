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

public slots:
    void on_chatUserClick(const QString &id);

private:
    bool _isConnectSql{false};
    QObject             *_root{nullptr};
    ChatRecordModel     *_model{nullptr};
    ChatRecordDBOperate *_db{nullptr};
};

#endif // CHARRECORDMANAGER_H
