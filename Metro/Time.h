#pragma once
#include<iostream>
#include<time.h>
#include<vector>
#include<string>
using namespace std;

class Times
{
public:
	string m_ID; //乘车人账号
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
	int m_trans; //换乘次数
	vector<int> m_MetroNum;
	vector<string> m_station; //记录车站
	void Show_Info();
};