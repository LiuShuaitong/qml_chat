#include "CharRecordManager.h"
#include <QQmlContext>

#define CHATRECORD    "chatrecord"

CharRecordManager::CharRecordManager(QObject *parent) : QObject(parent),
    _model(new ChatRecordModel(this)),
    _db(new ChatRecordDBOperate(this))
{

}

CharRecordManager::~CharRecordManager()
{
}

void CharRecordManager::registQMLEngine(const QQmlApplicationEngine &engine)
{
    engine.rootContext()->setContextProperty("$chat_record_manager",this);
    engine.rootContext()->setContextProperty("$record_model",_model);
}

void CharRecordManager::registQMLObject(QObject *object)
{
    _root = object;
}

void CharRecordManager::createDB()
{
    _isConnectSql = true;
    if(!_db->IsTabExists(CHATRECORD)){
        _db->createTab();

        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_1",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));


        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_2",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_3",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",true,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_4",false,"12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_5",false,"2020/12/20 12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_5",true,"2020/12/20 12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_5",false,"2020/12/20 12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_5",false,"2020/12/20 12:44:22",QStringLiteral("峡谷之巅，王者如你"),ChatRecordListData::Text));


        _db->insertTabData(ChatRecordListData(0,"Chat_6",true,"2020/12/20 13:44:02",QStringLiteral("人生如阶梯，若不往上走，就会往下行。你可画得出一个又上又下的楼梯么？"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_6",true,"2020/12/20 13:46:12",QStringLiteral("九十度很热，但这样的水温，能让水沸腾吗？"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_6",false,"2020/12/20 13:48:28",QStringLiteral("我在拉萨长大的。海拔高处沸点低"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_6",true,"19:12:28",QStringLiteral("走你"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_6",false,"20:44:27",QStringLiteral("禅师，水到沸点会发生什么现象"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_7",false,"12:10:22",QStringLiteral("把他拉出去给我毙了"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_7",false,"12:41:22",QStringLiteral("平常心，平常心，我是三十九号吴哲。"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_7",false,"12:46:22",QStringLiteral("一个精得像个鬼，一个笨的像头猪"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:40:22",QStringLiteral("许三多，我想看看你的表情"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:41:22",QStringLiteral("哭, 笑, 撒泼, 打滚,骂人.或者你一拳把我K.O.了"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:42:22",QStringLiteral("明明是个强人,天生一副熊样"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:43:22",QStringLiteral("舌头也是人，也要喘气"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:44:22",QStringLiteral("老七连兵活得不易"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:45:22",QStringLiteral("炊事班都没了，吃锅盖啊！"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:46:22",QStringLiteral("我不吃今天的饭，我不吃明天的饭，我三天不吃饭"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:47:22",QStringLiteral("你懂得做兵的这份尊严吗你?"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:48:22",QStringLiteral("不抛弃.也不放弃。所以我们就叫钢七连."),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:49:22",QStringLiteral("拿膏药一贴就重新装人"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",true,"20:50:22",QStringLiteral("得失我命，你来啰嗦（令人无限感慨，心疼）"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_8",false,"20:51:22",QStringLiteral("就他那记性是够泄密标准的!"),ChatRecordListData::Text));


        _db->insertTabData(ChatRecordListData(0,"Chat_9",true,"10:44:22",QStringLiteral("好好活，作有意义的事(有意义就是好好活，好好活，就是做很多很多有意义的事。)"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_9",false,"10:46:22",QStringLiteral("因为我才三十岁，我还没玩够呢！！！"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_9",false,"10:48:22",QStringLiteral("见不着面，抓不着人，想的你抓心挠肝的。"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_9",false,"10:49:22",QStringLiteral("你快跑呀，你看着我干什么，你瞧我被你逼成什么样了，你快跑你跑呀！"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_10",true,"2020/12/19 12:44:22",QStringLiteral("吃饭没？"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_10",false,"2020/12/19 12:45:22",QStringLiteral("南京大排档走起"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_11",false,"11:20:22",QStringLiteral("仁者无敌"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_11",true,"11:21:22",QStringLiteral("敌众我寡"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_11",false,"11:22:22",QStringLiteral("寡不敌众"),ChatRecordListData::Text));

        _db->insertTabData(ChatRecordListData(0,"Chat_12",false,"11:22:22",QStringLiteral("在干嘛"),ChatRecordListData::Text));
        _db->insertTabData(ChatRecordListData(0,"Chat_12",false,"12:22:41",QStringLiteral("看到回消息"),ChatRecordListData::Text));

    }
}

void CharRecordManager::on_chatUserClick(const QString &id)
{
    if(_isConnectSql)
    {
        _model->clear();
        QList<ChatRecordListData> list = _db->queryTabData(id);
        for(int i = 0;i < list.size();i++)
        {
            _model->insert(i,list.at(i));
        }
    }
}
