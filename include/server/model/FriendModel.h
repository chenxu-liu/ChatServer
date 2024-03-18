#pragma once
#include <vector>
#include "User.h"

using namespace std;
class FriendModel
{
public:
    bool insert(int user_id, int friend_id);
    // 返回用户好友列表
    vector<User> query(int user_id);
};