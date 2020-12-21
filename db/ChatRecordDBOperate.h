#ifndef CHATRECORDDBOPERATE_H
#define CHATRECORDDBOPERATE_H

#include "DBOperateBase.h"
#include "data/ChatRecordListData.h"

class ChatRecordDBOperate : public QObject
{
    Q_OBJECT
public:
    explicit ChatRecordDBOperate(QObject *parent = nullptr);

    ~ChatRecordDBOperate();

    /**
     * @brief createTab             创建数据表(chatlist)
     */
    void createTab(void);

    /**
     * @brief queryTabData          查找数据
     * @param id
     */
    QList<ChatRecordListData> queryTabData(const QString &userid);

    /**
     * @brief insertTabData         插入数据
     * @param data
     */
    void insertTabData(const ChatRecordListData &data);

    /**
     * @brief deleteTabData         删除数据
     * @param id
     */
    void deleteTabData(QString& id);

    /**
     * @brief deleteUserData        删除某一用户的全部记录
     * @param userid
     */
    void deleteUserData(const QString &userid);

    /**
     * @brief IsTabExists           判断数据表是否存在
     * @param tabName
     * @return
     */
    bool IsTabExists(QString tabName);

signals:

};

#endif // CHATRECORDDBOPERATE_H
