#pragma once
#include<iostream>
#include<string>
using namespace std;

class Users
{
public:
	string m_ID;//用户卡号
	string m_Name;//用户姓名
	string m_Key;//用户密码
	double m_Money;//用户余额
	string o_ID;//流水信息中对方卡号（转账时才有）
	string o_Name;//流水信息中对方姓名（转账时才有）
	double m_Turnover;//交易额
	int m_Type;//交易类型（1为存款、2为取款、3为转账、4为购票）
	void ShowInfo();//管理员查看信息函数
};