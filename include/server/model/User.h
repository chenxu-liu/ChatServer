#pragma once
#include <string>
using namespace std;
class User{
public:
    User(int id = -1, string name = "", string password = "", string state = "offline");
    void set_id(int id);
    void set_name(string name);
    void set_password(string password);
    void set_state(string state);
    int get_id();
    string get_name();
    string get_password();
    string get_state();
private:
    int id_;
    string name_;
    string password_;
    string state_;

};