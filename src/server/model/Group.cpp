#include "Group.h"
Group::Group(int id, string name, string desc)
{
    id_ = id;
    name_ = name;
    desc_ = desc;
}

void Group::set_id(int id)
{
    id_ = id;
}

void Group::set_name(string name)
{
    name_ = name;
}

void Group::set_desc(string desc)
{
    desc_ = desc;
}

int Group::get_id()
{
    return id_;
}

string Group::get_name()
{
    return name_;
}

string Group::get_desc()
{
    return desc_;
}

vector<GroupUser> &Group::get_User()
{
    return user_;
}