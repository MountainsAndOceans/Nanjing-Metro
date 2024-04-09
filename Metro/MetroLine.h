#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;

class MetroLine
{
public:
	int m_ID; //地铁线路
	map<int, string> m; //第一个int是到起点站站距，string是车站名称
	void Show_Info(); //显示车站信息函数
	int Take_Train(string Name1, string Name2); //计算乘车站距（同一条线路）
};