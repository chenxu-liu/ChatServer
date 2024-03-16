#include "ChatServer.h"
ChatServer::ChatServer(muduo::net::EventLoop* loop,
                       const muduo::net::InetAddress& listenAddr)
  : server_(loop, listenAddr, "EchoServer")
{
  server_.setConnectionCallback(
      std::bind(&ChatServer::onConnection, this, _1));
  server_.setMessageCallback(
      std::bind(&ChatServer::onMessage, this, _1, _2, _3));
}

void ChatServer::start()
{
  server_.start();
}

void ChatServer::onConnection(const muduo::net::TcpConnectionPtr& conn)
{
  LOG_INFO << "ChatServer - " << conn->peerAddress().toIpPort() << " -> "
           << conn->localAddress().toIpPort() << " is "
           << (conn->connected() ? "UP" : "DOWN");
}

void ChatServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
                           muduo::net::Buffer* buffer,
                           muduo::Timestamp time)
{
  string buf = buffer->retrieveAllAsString();
  //反序列化josn字符串
  json js = json::parse(buf);
  //解耦网络和业务模块的代码
  //通过js里面的msgid，绑定msgid的回调函数，获取业务处理器handler
  auto msg_handler = Service::getService()->get_handler(js["msgid"].get<int>());
  msg_handler(conn,js,time);

}

