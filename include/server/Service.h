#pragma once
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Logging.h>
#include <unordered_map>
#include <functional>
#include "json.hpp"
#include "public.h"
#include "UserModel.h"
using namespace std;
using namespace muduo;
using namespace muduo::net;
using json=nlohmann::json;
using  MsgHandler = function<void(const TcpConnectionPtr &conn, json &js, Timestamp time)>;

class Service{
public:
    static Service * getService();
    //登录
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //注册
    void regist(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //一对一聊天业务
    void one_chat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //添加好友业务
    bool add_friend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //创建 群组
    bool create_group(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //加入群组
    bool add_group(const TcpConnectionPtr &conn, json &js, Timestamp time);
     //群聊业务
    void group_chat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //注销业务
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //获取消息对应的处理器
    MsgHandler get_handler(int msgid);

private:
    Service();
    unordered_map<int, MsgHandler>  msg_handler_map_;
    UserModel user_model_;
};