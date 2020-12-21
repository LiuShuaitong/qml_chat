#include "Manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    QObject::connect(&_userManager,SIGNAL(sig_chatUserClick(QString)),&_recordManager,SLOT(on_chatUserClick(QString)));
    QObject::connect(&_recordManager,SIGNAL(sig_addChatMsg(QString,QString,QString)),&_userManager,SLOT(on_addChatMsg(QString,QString,QString)));

    _isConnect = _db.openDB();
    if(_isConnect)
    {
        _userManager.createDB();
        _recordManager.createDB();
        _userManager.loadChatListData();
    }
}

Manager::~Manager()
{
    if(_isConnect)
    {
        _db.closeDB();
    }
}

void Manager::registQMLEngine(const QQmlApplicationEngine &engine)
{
    _userManager.registQMLEngine(engine);
    _recordManager.registQMLEngine(engine);
}

void Manager::registQMLObject(QObject *object)
{
    _userManager.registQMLObject(object);
    _recordManager.registQMLObject(object);
}

