#include "ChatListManager.h"
#include <QQmlContext>

#define CHATLIST    "chatlist"

ChatListManager::ChatListManager(QObject *parent) :
    QObject(parent),
    _model(new ChatListModel(this)),
    _sqlOperator(new ChatUserDBOperate(this))
{
    _isConnectSql = _sqlOperator->openDB();
    if(_isConnectSql){
        if(!_sqlOperator->IsTabExists(CHATLIST)){
            _sqlOperator->createTab();
            _sqlOperator->insertTabData(ChatUserListData("1",QStringLiteral("忆柳"),"12:44:22","峡谷之巅，王者如你"));
            _sqlOperator->insertTabData(ChatUserListData("2",QStringLiteral("尔岚"),"11:33:44","翻过那座山，让他们听到你们的故事"));
            _sqlOperator->insertTabData(ChatUserListData("3",QStringLiteral("蔡山林"),"10:06:33","剑纵横三万，剑光寒九洲"));
            _sqlOperator->insertTabData(ChatUserListData("4",QStringLiteral("陈诚"),"2020/12/26","破茧成蝶一线间，秒天秒地秒神仙"));
            _sqlOperator->insertTabData(ChatUserListData("5",QStringLiteral("蔡勇"),"2020/12/15","Uzi还没死，还在秀，竟然还没死"));
            _sqlOperator->insertTabData(ChatUserListData("6",QStringLiteral("正志"),"2020/12/10","我们是冠军"));
            _sqlOperator->insertTabData(ChatUserListData("7",QStringLiteral("子石"),"2020/11/30","老兵不死只是逐渐凋亡"));
            _sqlOperator->insertTabData(ChatUserListData("8",QStringLiteral("梦璐"),"2020/11/29","剑气纵横十万里，一剑霜寒十九州"));
            _sqlOperator->insertTabData(ChatUserListData("9",QStringLiteral("慕青"),"2020/11/27","谁敢横刀立马 唯我虎大将军啊"));
            _sqlOperator->insertTabData(ChatUserListData("10",QStringLiteral("雪柳"),"2020/11/24","我们是冠军！我们又是冠军！！"));
            _sqlOperator->insertTabData(ChatUserListData("11",QStringLiteral("向珊"),"2020/11/23","杀尺帝！杀尺帝啊！"));
            _sqlOperator->insertTabData(ChatUserListData("12",QStringLiteral("易烟"),"2020/11/22","顺风简自豪，逆风狂小狗，绝境uzi"));
        }
    }
    loadChatListData();
}

ChatListManager::~ChatListManager()
{
    if(_isConnectSql){
        _sqlOperator->closeDB();
    }
}

void ChatListManager::registQMLEngine(const QQmlApplicationEngine &engine)
{
    engine.rootContext()->setContextProperty("$Model",_model);
    engine.rootContext()->setContextProperty("$chatmanager",this);
}

void ChatListManager::search(const QString &name)
{
    if(_isConnectSql)
    {
        _model->clear();
        QList<ChatUserListData> list = _sqlOperator->queryTabData(name);
        for(int i = 0;i < list.size();i++)
        {
            _model->insert(i,list.at(i));
        }
    }
}

void ChatListManager::loadChatListData()
{
    if(_isConnectSql)
    {
        QList<ChatUserListData> list = _sqlOperator->queryTabData();
        for(int i = 0;i < list.size();i++)
        {
            _model->insert(i,list.at(i));
        }
    }
}
