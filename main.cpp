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
    cout << "ע��ʱ���벻Ҫ�пո��������ţ�" << endl;

    cout << "select a username: "; cin >> username;
    cout << "select a password: "; cin >> password;

    if (my.my_Register(username, password))
    {
        printf("ע��ɹ���\n");
    }
    else
    {
        printf("ע��ʧ�ܣ�\n");
        return false;
    }

    return true;
}

//��¼
bool cat_Login()
{
    string username, password, un, pw;
    cout << "��½ʱ���벻Ҫ�пո��������ţ�" << endl;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    if (my.my_Login(username, password))
    {
        printf("��¼�ɹ���\n");
        return true;
    }

    return false;
}

int main()
{
    cout << "====================================" << endl;
    //islogin=true�����¼��flag=0�����˳�
    int flag = 1;
    bool islogin = false;
    while (flag)
    {
        int index;
        cout << "1. ע��\n2. ��¼\n����Ϊ�˳�\n������Ҫִ�еĲ�����";
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
        cout << "�ѵ�½!!!" << endl;
    else
        cout << "ɶҲû����!" << endl;
    return 0;
}


