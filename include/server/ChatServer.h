#pragma once
#include <muduo/net/TcpServer.h>
#include <muduo/base/Logging.h>

#include <muduo/net/EventLoop.h>
#include <functional>
#include <string>
#include "json.hpp"
#include "Service.h"
using namespace std;
using json=nlohmann::json;
using namespace placeholders;
// 使用muduo开发回显服务器
class ChatServer
{
 public:
  ChatServer(muduo::net::EventLoop* loop,
             const muduo::net::InetAddress& listenAddr);

  void start(); 

 private:
  void onConnection(const muduo::net::TcpConnectionPtr& conn);

  void onMessage(const muduo::net::TcpConnectionPtr& conn,
                 muduo::net::Buffer* buf,
                 muduo::Timestamp time);

  muduo::net::TcpServer server_;
};