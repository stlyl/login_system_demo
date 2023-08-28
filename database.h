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
    const char* m_host; // ������ַ
    const char* m_username; // �û���
    const char* m_password; // ����
    const char* m_database; // ���ӵ����ݿ�����database
    unsigned int   m_port; // Mysql�˿ںţ�Ĭ��3306
    const char* m_unix_socket; // unix���ӱ�ʶ��һ��Ĭ��ΪNULL
    unsigned long  m_clientflag; // �ͻ������ӱ�־��һ��Ĭ��Ϊ0

private:
    MYSQL m_Mysql; // Mysql���Ӿ��
    MYSQL_RES* m_SelectResult = NULL; // ���ڴ洢Mysql��ѯ�������

public:
    //���캯��
    Cat_Mysql();
    //��������
    ~Cat_Mysql();

public:
    //��ʼ�����ݿ�
    bool my_Init();
    //�ͷ����ݿ���Դ
    void my_FreeConnect();
    //sql���ִ��
    bool my_RunSql(const char* sql);
    //sql����ѯ
    bool my_SelectData(const char* sql);
    //��ӡ���
    void my_PrintData();

    //���幦�ܺ�������
public:
    //ע����֤
    bool my_Register(std::string& un, std::string& pw);
    //��¼��֤
    bool my_Login(std::string& un, std::string& pw);
};

