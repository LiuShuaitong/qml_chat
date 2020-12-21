#include "ChatUserManager.h"
#include <QQmlContext>

#define CHATLIST    "chatlist"

ChatUserManager::ChatUserManager(QObject *parent) :
    QObject(parent),
    _model(new ChatUserModel(this)),
    _sqlOperator(new ChatUserDBOperate(this))
{
}

ChatUserManager::~ChatUserManager()
{
}

void ChatUserManager::createDB()
{
    _isConnectSql = true;

    if(!_sqlOperator->IsTabExists(CHATLIST)){
        _sqlOperator->createTab();
        _sqlOperator->insertTabData(ChatUserListData("Chat_1",QStringLiteral("忆柳"),"12:44:22","峡谷之巅，王者如你"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_2",QStringLiteral("尔岚"),"11:33:44","翻过那座山，让他们听到你们的故事"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_3",QStringLiteral("蔡山林"),"10:06:33","剑纵横三万，剑光寒九洲"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_4",QStringLiteral("陈诚"),"2020/12/26","破茧成蝶一线间，秒天秒地秒神仙"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_5",QStringLiteral("蔡勇"),"2020/12/15","Uzi还没死，还在秀，竟然还没死"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_6",QStringLiteral("正志"),"2020/12/10","我们是冠军"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_7",QStringLiteral("子石"),"2020/11/30","老兵不死只是逐渐凋亡"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_8",QStringLiteral("梦璐"),"2020/11/29","剑气纵横十万里，一剑霜寒十九州"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_9",QStringLiteral("慕青"),"2020/11/27","谁敢横刀立马 唯我虎大将军啊"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_10",QStringLiteral("雪柳"),"2020/11/24","我们是冠军！我们又是冠军！！"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_11",QStringLiteral("向珊"),"2020/11/23","杀尺帝！杀尺帝啊！"));
        _sqlOperator->insertTabData(ChatUserListData("Chat_12",QStringLiteral("易烟"),"2020/11/22","顺风简自豪，逆风狂小狗，绝境uzi"));
    }
}

void ChatUserManager::registQMLEngine(const QQmlApplicationEngine &engine)
{
    engine.rootContext()->setContextProperty("$chat_model",_model);
    engine.rootContext()->setContextProperty("$chat_list_manager",this);
}

void ChatUserManager::registQMLObject(QObject *object)
{
    _root = object;
}

void ChatUserManager::search(const QString &name)
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
#include <QLabel>
void ChatUserManager::clickChatList(int index)
{
    if(_model)
    {
        QString id = _model->data(_model->index(index,0),ChatUserModel::IDRole).toString();
        QString name = _model->data(_model->index(index,0),ChatUserModel::NAMERole).toString();
        if(_root)
        {
            // 通过值绑定的方式调用
            setName(name);
            // 发送信号
            emit sig_chatUserClick(id);

            // C++ 调用QML
            QObject *pRectangle = _root->findChild<QObject *>("id_chat_form");
            if( pRectangle )
            {
                QVariant returnedValue;
                QMetaObject::invokeMethod(pRectangle, "chatName", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, name));
            }
            else
            {
                qDebug() << "findChild object id_chat_form failed.";
            }
        }
    }
}

void ChatUserManager::setName(const QString &name)
{
    if(_name!=name){
        _name = name;
        emit nameChanged(name);
    }
}

QString ChatUserManager::getName() const
{
    return _name;
}

void ChatUserManager::loadChatListData()
{
    if(_isConnectSql)
    {
        _model->clear();
        QList<ChatUserListData> list = _sqlOperator->queryTabData();
        for(int i = 0;i < list.size();i++)
        {
            _model->insert(i,list.at(i));
        }
        if(list.size() > 0){
            setName(list.first().name());
            emit sig_chatUserClick(list.first().id());
        }
    }
}

void ChatUserManager::on_addChatMsg(const QString &userid, const QString &msg,const QString &time)
{
    // 更新列表显示
    ChatUserListData data = _model -> update(userid,msg,time);
    // 写入数据库
    if(_isConnectSql && !data.id().isEmpty())
    {
        _sqlOperator->updateTabData(data);
    }
}
