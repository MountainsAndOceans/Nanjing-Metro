#pragma once
#include<iostream>
#include<string>
using namespace std;

class Users
{
public:
	string m_ID;//�û�����
	string m_Name;//�û�����
	string m_Key;//�û�����
	double m_Money;//�û����
	string o_ID;//��ˮ��Ϣ�жԷ����ţ�ת��ʱ���У�
	string o_Name;//��ˮ��Ϣ�жԷ�������ת��ʱ���У�
	double m_Turnover;//���׶�
	int m_Type;//�������ͣ�1Ϊ��2Ϊȡ�3Ϊת�ˡ�4Ϊ��Ʊ��
	void ShowInfo();//����Ա�鿴��Ϣ����
};