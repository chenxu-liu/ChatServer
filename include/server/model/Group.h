#pragma once
#include <string>
#include <vector>
#include "GroupUser.h"
using namespace std;
//Group表的ORM类
class Group
{
public:
    Group(int id = -1, string name = "", string desc = "");

    void set_id(int id);

    void set_name(string name);

    void set_desc(string desc);

    int get_id();

    string get_name();
    string get_desc();

    vector<GroupUser> &get_User();

private:
    int id_;
    string name_;
    string desc_;
    vector<GroupUser> user_;
};