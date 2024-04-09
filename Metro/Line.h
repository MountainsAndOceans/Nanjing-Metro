#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include"MetroLine.h"
#include"GlobalFile.h"
#include"Users.h"
#include"Time.h"
using namespace std;

class Line
{
public:
	vector<MetroLine> v; //储存所有线路的容器
	vector<Users> u; //储存所有客户信息的容器
	vector<Times> t; //储存乘车记录的容器
	Line(); //构造函数，读取数据信息
	void Read_Info(string filename); //读取地铁线路信息至容器函数
	void Save_Info(int Line_Num); //储存地铁信息函数
	void Read_Passenger(); //读取乘客信息函数
	void Save_Passenger(); //储存乘客信息函数
	void Save_Water(string ID); //储存流水信息函数
	void Admin_Login(); //管理员登录函数
	void Admin_Menu(); //管理员菜单函数
	void Add_Station(); //添加车站函数
	void Delete_Station(); //删除车站函数
	void Correct_Station(); //修改车站信息函数
	void Look_Info(); //查询车站信息函数
	void Find_Line(string Name, int* p); //找出Name站在哪些线路上
	void No_Change(string Name1, string Name2, int* p); //判断Name1和Name2是否在同一条线上，在则返回同一线路的号码
	string ID_Key(char* Pw); //输入账号密码函数，返回账号
	int Find_Transfer(int ID, string* p); //查询ID号线上的所有换乘车站，返回换乘车站的数量
	string Passenger_Login();
	void Passenger_Menu();
	void Passenger();
	void Passenger_Buy_Ticket(string ID);
	int Cost_Money(int Distance);
	void Read_Time(); //读取乘车记录
	void Save_Time(); //记录乘车记录
	void Check_Time(string ID); //查询乘车记录
};