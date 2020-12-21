#ifndef CHATUSERDBOPERATE_H
#define CHATUSERDBOPERATE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include "data/ChatUserListData.h"

class ChatUserDBOperate : public QObject
{
    Q_OBJECT
public:
    explicit ChatUserDBOperate(QObject *parent = nullptr);
    ~ChatUserDBOperate();
    /**
     * @brief openDB                建立连接
     * @return
     */
    bool openDB(void);

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
     * @brief insertTabData         插入数据
     * @param data
     */
    void insertTabData(const ChatUserListData &data);

    /**
     * @brief IsTabExists           判断数据表是否存在
     * @param tabName
     * @return
     */
    bool IsTabExists(QString tabName);

    /**
     * @brief deleteTabData         删除数据
     * @param id
     */
    void deleteTabData(QString& id);

    /**
     * @brief closeDB               关闭数据库
     */
    void closeDB(void);

private:

    QSqlDatabase _db;//用于建立和数据库的连接
};

#endif // CHATUSERDBOPERATE_H
