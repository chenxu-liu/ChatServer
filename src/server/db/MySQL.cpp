#include "MySQL.h"

// 初始化数据库连接
MySQL::MySQL()
{
    conn_ = mysql_init(nullptr);
}
// 释放连接
MySQL::~MySQL()
{
    if (conn_ != nullptr)
    {
        mysql_close(conn_);
    }
}
// 连接数据库
bool MySQL::connet()
{
    MYSQL *p = mysql_real_connect(conn_, SERVER, USER, PASSWORD, DBNAME, 3306, nullptr, 0);
    if (p != nullptr)
    {
        // 代码支持中文，因为默认是ASCII
        mysql_query(conn_, "set names gbk");
        LOG_INFO << "connect mysql success!";
    }
    else
    {
        LOG_INFO << "connect mysql fail!";
    }

    return p;
}
// 更新操作
bool MySQL::update(string sql)
{
    if (mysql_query(conn_, sql.c_str()))
    {
        LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " update error!";
        return false;
    }
    return true;
}
// 查询操作
MYSQL_RES *MySQL::query(string sql)
{
    if (mysql_query(conn_, sql.c_str()))
    {
        LOG_INFO << __FILE__ << " : " << __LINE__ << " : " << sql << " select error!";
        return nullptr;
    }
    return mysql_use_result(conn_);
}
// 获取连接
MYSQL *MySQL::get_connection()
{
    return conn_;
}
