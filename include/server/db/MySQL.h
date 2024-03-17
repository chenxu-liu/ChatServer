#pragma once
#include <string>
#include <mysql/mysql.h>
#include <muduo/base/Logging.h>

using namespace std;

#define SERVER "127.0.0.1"
#define USER "liuchenxu"
#define PASSWORD "123456"
#define DBNAME "chat"

class MySQL
{
public:
    // 初始化数据库连接
    MySQL();
    // 释放连接
    ~MySQL();
    // 连接数据库
    bool connet();
    // 更新操作
    bool update(string sql);
    // 查询操作
    MYSQL_RES *query(string sql);
    // 获取连接
    MYSQL *get_connection();

private:
    MYSQL *conn_;
};