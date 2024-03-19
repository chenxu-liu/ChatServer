#pragma once
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Logging.h>
#include <unordered_map>
#include <functional>
#include <mutex>
#include "json.hpp"
#include "public.h"
#include "UserModel.h"
#include "FriendModel.h"
#include "Group.h"
#include "OfflineMessageModel.h"
#include "GroupModel.h"
#include "GroupUser.h"
using namespace std;
using namespace muduo;
using namespace muduo::net;
using json = nlohmann::json;
using MsgHandler = function<void(const TcpConnectionPtr &conn, json &js, Timestamp time)>;

class Service
{
public:
    static Service *getService();
    // 登录
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 注册
    void regist(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 一对一聊天业务
    void one_chat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 添加好友业务
    bool add_friend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 创建 群组
    bool create_group(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 加入群组
    bool add_group(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 群聊业务
    void group_chat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 注销业务
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 获取消息对应的处理器
    MsgHandler get_handler(int msgid);

private:
    Service();
    unordered_map<int, MsgHandler> msg_handler_map_;
    UserModel user_model_;
    FriendModel friend_model_;
    OfflineMessageModel offline_message_model_;
    GroupModel group_model_;
    // 存储在线用户的连接情况，便于服务器给用户发消息，注意线程安全
    unordered_map<int, TcpConnectionPtr> user_connection_map_;
    mutex conn_mutex_;
};