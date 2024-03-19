#pragma once
#include "User.h"

class GroupUser : public User
{
public:
    void set_role(string role);
    string get_role();
private:
    string role_;
};