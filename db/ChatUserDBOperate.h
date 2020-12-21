#ifndef CHATUSERDBOPERATE_H
#define CHATUSERDBOPERATE_H

#include "DBOperateBase.h"
#include "data/ChatUserListData.h"

class ChatUserDBOperate : public QObject
{
    Q_OBJECT
public:
    explicit ChatUserDBOperate(QObject *parent = nullptr);
    ~ChatUserDBOperate();

    /**
     * @brief createTab             创建数据表(chatlist)
     */
    void createTab(void);

    /**
     * @brief queryTabData          查找数据
     * @param id
     */
    QList<ChatUserListData> queryTabData(const QString &name = "");

    /**
     * @brief updateTabData         更新数据库
     * @param data
     */
    void updateTabData(const ChatUserListData &data);

    /**
     * @brief insertTabData         插入数据
     * @param data
     */
    void insertTabData(const ChatUserListData &data);

    /**
     * @brief deleteTabData         删除数据
     * @param id
     */
    void deleteTabData(QString& id);

    /**
     * @brief IsTabExists           判断数据表是否存在
     * @param tabName
     * @return
     */
    bool IsTabExists(QString tabName);

private:

};

#endif // CHATUSERDBOPERATE_H
