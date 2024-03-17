#include "User.h"
User::User(int id, string name, string password, string state)
{
    id_ = id;
    name_ = name;
    password_ = password;
    state_ = state;
}

void User::set_id(int id)
{
    id_ = id;
}

void User::set_name(string name)
{
    name_ = name;
}

void User::set_password(string password)
{
    password_ = password;
}

void User::set_state(string state)
{
    state_ = state;
}

int User::get_id()
{
    return id_;
}

string User::get_name()
{
    return name_;
}

string User::get_password()
{
    return password_;
}

string User::get_state()
{
    return state_;
}
