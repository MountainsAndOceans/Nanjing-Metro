#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;

class MetroLine
{
public:
	int m_ID; //������·
	map<int, string> m; //��һ��int�ǵ����վվ�࣬string�ǳ�վ����
	void Show_Info(); //��ʾ��վ��Ϣ����
	int Take_Train(string Name1, string Name2); //����˳�վ�ࣨͬһ����·��
};