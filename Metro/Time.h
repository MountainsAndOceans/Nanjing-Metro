#pragma once
#include<iostream>
#include<time.h>
#include<vector>
#include<string>
using namespace std;

class Times
{
public:
	string m_ID; //�˳����˺�
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
	int m_trans; //���˴���
	vector<int> m_MetroNum;
	vector<string> m_station; //��¼��վ
	void Show_Info();
};