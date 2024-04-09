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
	vector<MetroLine> v; //����������·������
	vector<Users> u; //�������пͻ���Ϣ������
	vector<Times> t; //����˳���¼������
	Line(); //���캯������ȡ������Ϣ
	void Read_Info(string filename); //��ȡ������·��Ϣ����������
	void Save_Info(int Line_Num); //���������Ϣ����
	void Read_Passenger(); //��ȡ�˿���Ϣ����
	void Save_Passenger(); //����˿���Ϣ����
	void Save_Water(string ID); //������ˮ��Ϣ����
	void Admin_Login(); //����Ա��¼����
	void Admin_Menu(); //����Ա�˵�����
	void Add_Station(); //��ӳ�վ����
	void Delete_Station(); //ɾ����վ����
	void Correct_Station(); //�޸ĳ�վ��Ϣ����
	void Look_Info(); //��ѯ��վ��Ϣ����
	void Find_Line(string Name, int* p); //�ҳ�Nameվ����Щ��·��
	void No_Change(string Name1, string Name2, int* p); //�ж�Name1��Name2�Ƿ���ͬһ�����ϣ����򷵻�ͬһ��·�ĺ���
	string ID_Key(char* Pw); //�����˺����뺯���������˺�
	int Find_Transfer(int ID, string* p); //��ѯID�����ϵ����л��˳�վ�����ػ��˳�վ������
	string Passenger_Login();
	void Passenger_Menu();
	void Passenger();
	void Passenger_Buy_Ticket(string ID);
	int Cost_Money(int Distance);
	void Read_Time(); //��ȡ�˳���¼
	void Save_Time(); //��¼�˳���¼
	void Check_Time(string ID); //��ѯ�˳���¼
};