#pragma once
//#ifndef _CAT_MYSQL__H_
//#define _CAT_MYSQL__H_
#include <iostream>
#include <mysql.h>
#include <iomanip>
#include <string>
class Cat_Mysql
{
private:
    const char* m_host; // 主机地址
    const char* m_username; // 用户名
    const char* m_password; // 密码
    const char* m_database; // 连接的数据库名称database
    unsigned int   m_port; // Mysql端口号，默认3306
    const char* m_unix_socket; // unix连接标识，一般默认为NULL
    unsigned long  m_clientflag; // 客户端连接标志，一般默认为0

private:
    MYSQL m_Mysql; // Mysql连接句柄
    MYSQL_RES* m_SelectResult = NULL; // 用于存储Mysql查询结果集合

public:
    //构造函数
    Cat_Mysql();
    //析构函数
    ~Cat_Mysql();

public:
    //初始化数据库
    bool my_Init();
    //释放数据库资源
    void my_FreeConnect();
    //sql语句执行
    bool my_RunSql(const char* sql);
    //sql语句查询
    bool my_SelectData(const char* sql);
    //打印结果
    void my_PrintData();

    //具体功能函数放这
public:
    //注册验证
    bool my_Register(std::string& un, std::string& pw);
    //登录验证
    bool my_Login(std::string& un, std::string& pw);
};

