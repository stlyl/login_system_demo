#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
Cat_Mysql my;
bool cat_Register()
{
    string username, password;
    cout << "注册时，请不要有空格和特殊符号！" << endl;

    cout << "select a username: "; cin >> username;
    cout << "select a password: "; cin >> password;

    if (my.my_Register(username, password))
    {
        printf("注册成功！\n");
    }
    else
    {
        printf("注册失败！\n");
        return false;
    }

    return true;
}

//登录
bool cat_Login()
{
    string username, password, un, pw;
    cout << "登陆时，请不要有空格和特殊符号！" << endl;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    if (my.my_Login(username, password))
    {
        printf("登录成功！\n");
        return true;
    }

    return false;
}

int main()
{
    cout << "====================================" << endl;
    //islogin=true代表登录，flag=0代表退出
    int flag = 1;
    bool islogin = false;
    while (flag)
    {
        int index;
        cout << "1. 注册\n2. 登录\n其余为退出\n请输入要执行的操作：";
        cin >> index;
        switch (index)
        {
        case 1:
            cat_Register();
            break;

        case 2:
            if (cat_Login())
            {
                islogin = true;
                flag = 0;
            }
            break;

        default:
            flag = 0;
            break;
        }
    }

    if (islogin)
        cout << "已登陆!!!" << endl;
    else
        cout << "啥也没发生!" << endl;
    return 0;
}


