#ifndef DBOPERATEBASE_H
#define DBOPERATEBASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

class DBOperateBase : public QObject
{
    Q_OBJECT
public:
    explicit DBOperateBase(QObject *parent = nullptr);

    /**
     * @brief openDB                建立连接
     * @return
     */
    bool openDB(void);

    /**
     * @brief closeDB               关闭数据库
     */
    void closeDB(void);

signals:

private:
    QSqlDatabase _db;//用于建立和数据库的连接
};

#endif // DBOPERATEBASE_H
