#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <manager/ChatUserManager.h>
#include <manager/CharRecordManager.h>
#include "db/DBOperateBase.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

    ~Manager();

    /**
     * @brief registQMLEngine       注册QML事件
     * @param engine
     */
    void registQMLEngine(const QQmlApplicationEngine &engine);

    void registQMLObject(QObject *object);

signals:

private:
    bool _isConnect{false};
    DBOperateBase _db;
    ChatUserManager _userManager;
    CharRecordManager _recordManager;
};

#endif // MANAGER_H
