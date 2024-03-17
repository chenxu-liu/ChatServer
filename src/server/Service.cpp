#include "Service.h"

Service *Service::getService(){
    static Service service;
    return &service;
}

Service::Service(){
    msg_handler_map_.insert({LOGIN_MSG, bind(&Service::login, this, _1, _2, _3)});
    msg_handler_map_.insert({LOGINOUT_MSG, bind(&Service::loginout, this, _1, _2, _3)});
    msg_handler_map_.insert({REG_MSG, bind(&Service::regist, this, _1, _2, _3)});
    msg_handler_map_.insert({ONE_CHAT_MSG, bind(&Service::one_chat, this, _1, _2, _3)});
    msg_handler_map_.insert({ADD_FRIEND_MSG, bind(&Service::add_friend, this, _1, _2, _3)});
    msg_handler_map_.insert({CREATE_GROUP_MSG, bind(&Service::create_group, this, _1, _2, _3)});
    msg_handler_map_.insert({ADD_GROUP_MSG, bind(&Service::add_group, this, _1, _2, _3)});
    msg_handler_map_.insert({GROUP_CHAT_MSG, bind(&Service::group_chat, this, _1, _2, _3)});
}

// 登录
void Service::login(const TcpConnectionPtr &conn, json &js, Timestamp time){
    int id = js["id"].get<int>();
    string password = js["password"];
    User user = user_model_.query(id);
     if (user.get_id() == id && user.get_password() == password)
    {
         //用户在线
        if (user.get_state() == "online")
        {
            //用户不存在
            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 2;
            response["errmsg"] = "id is online";

            conn->send(response.dump());
        }
        //...........
        //...........
        //待完善
        //...........
    }


}
// 注册
void Service::regist(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 一对一聊天业务
void Service::one_chat(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 添加好友业务
bool Service::add_friend(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 创建 群组
bool Service::create_group(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 加入群组
bool Service::add_group(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 群聊业务
void Service::group_chat(const TcpConnectionPtr &conn, json &js, Timestamp time){
}
// 注销业务
void Service::loginout(const TcpConnectionPtr &conn, json &js, Timestamp time){
}

// 获取消息对应的处理器
MsgHandler Service::get_handler(int msgid){
    auto it = msg_handler_map_.find(msgid);
    if(it == msg_handler_map_.end()){
         //返回一个默认处理器，打印错误日志
        return [=](const TcpConnectionPtr &conn, json &js, Timestamp time) {
            LOG_ERROR << "msgid: " << msgid << " can not find handler!";
        };
    } else
    {
        return msg_handler_map_[msgid];
    }
}
