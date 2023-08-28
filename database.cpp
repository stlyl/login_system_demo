#include "database.h"
#include <iostream>
#include <mysql.h>
#include <vector>
#include <string>
using namespace std;

Cat_Mysql::Cat_Mysql()
{
	m_host = "localhost";
	m_username = "root";
	m_password = "123456";
	m_database = "login_sys";
	m_port = 3306;
	m_unix_socket = NULL;
	m_clientflag = 0;

	my_Init();
}
Cat_Mysql::~Cat_Mysql()
{
	my_FreeConnect();
}
bool Cat_Mysql::my_Init()
{
	if (!mysql_init(&m_Mysql))
	{
		printf("Mysql��ʼ��ʧ��!\n");
		return false;
	}
	mysql_options(&m_Mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&m_Mysql, m_host, m_username, m_password,
		m_database, m_port, m_unix_socket, m_clientflag))
	{
		printf("���ݿ�����ʧ��!\n");
		return false;
	}
	return true;
}
bool Cat_Mysql::my_Register(std::string& un, std::string& pw)
{
	string sql = "SELECT * FROM loginsys";
	if (mysql_query(&m_Mysql, sql.c_str()))
	{
		printf("��ѯʧ��!\n");
		return false;
	}
	m_SelectResult = mysql_store_result(&m_Mysql);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(m_SelectResult))
	{
		if (row[1] == un) {
			cout << "���û���ע��!" << endl;
			return false;
		}
	}
	sql = "INSERT INTO loginsys(username, password) VALUES(\"" + un + "\", \"" + pw + "\")";
	cout << "ִ��sql��䣺" << sql << endl;
	if (mysql_query(&m_Mysql, sql.c_str()))
	{
		printf("sql���ִ��ʧ��!\n");
		return false;
	}

	printf("sql���ִ�гɹ�!\n");
	return true;
}
bool Cat_Mysql::my_Login(std::string& un, std::string& pw)
{
	cout << "�������Ϣ��" << un << "  " << pw << endl;
	string sql = "SELECT * FROM loginsys";
	cout << "ִ��sql��䣺" << sql << endl;
	if (mysql_query(&m_Mysql, sql.c_str()))
	{
		printf("��ѯʧ��!\n");
		return false;
	}
	m_SelectResult = mysql_store_result(&m_Mysql);
	if (!m_SelectResult) {
		printf("û�и��û�\n");
		return false;
	}
	MYSQL_ROW row;
	while (row = mysql_fetch_row(m_SelectResult))
	{
		cout << "row[1]: " << row[1] << " " << "row[3]: " << row[3]  << endl;
		if (row[1] == un && row[3] == pw) 
			return true;
	}
	cout << "�˺Ż����������!" << endl;
	return false;
}

//�ͷ�
void Cat_Mysql::my_FreeConnect()
{
	cout << "====================================" << endl;
	printf("��ʼ����Mysql����!\n");
	mysql_free_result(m_SelectResult);
	mysql_close(&m_Mysql);
	return;
}
