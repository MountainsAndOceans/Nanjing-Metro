#include"MetroLine.h"
void MetroLine::Show_Info()
{
	if (this->m_ID < 100)
	{
		cout << this->m_ID << "���ߣ�" << endl;
	}
	else if (this->m_ID == 101)
	{
		cout << "S1����" << endl;
	}
	else if (this->m_ID == 103)
	{
		cout << "S3����" << endl;
	}
	else if (this->m_ID == 106)
	{
		cout << "S6����" << endl;
	}
	else if (this->m_ID == 107)
	{
		cout << "S7����" << endl;
	}
	else if (this->m_ID == 108)
	{
		cout << "S8����" << endl;
	}
	else if (this->m_ID == 109)
	{
		cout << "S9����" << endl;
	}
	for (map<int, string>::iterator mt = this->m.begin(); mt != this->m.end(); mt++)
	{
		cout << "��վ��ţ�" << mt->first << " ��վ���ƣ�" << mt->second << endl;
	}
}
int MetroLine::Take_Train(string Name1, string Name2) //ͨ��map�����ĵ�һ��intֵ������վ�࣬�β�Ϊ������վվ��
{
	/*����������վ�ĳ�վ����Լ���վ��*/
	int Pos1 = 0;
	int Pos2 = 0;
	for (map<int, string>::iterator mt = this->m.begin(); mt != this->m.end(); mt++) //��map�������ҵ�������վ�ı��
	{
		if (mt->second == Name1)
		{
			Pos1 = mt->first;
		}
		if (mt->second == Name2)
		{
			Pos2 = mt->first;
		}
	}
	string Line_Num;
	switch (this->m_ID) //ȷ��������·
	{
	case 1:Line_Num = "1"; break;
	case 2:Line_Num = "2"; break;
	case 3:Line_Num = "3"; break;
	case 4:Line_Num = "4"; break;
	case 5:Line_Num = "5"; break;
	case 7:Line_Num = "7"; break;
	case 10:Line_Num = "10"; break;
	case 101:Line_Num = "S1"; break;
	case 103:Line_Num = "S3"; break;
	case 106:Line_Num = "S6"; break;
	case 107:Line_Num = "S7"; break;
	case 108:Line_Num = "S8"; break;
	case 109:Line_Num = "S9"; break;
	default:
		break;
	}
	cout << "�ӡ�" << Name1 << "��վ����" << Name2 << "��վ��Ҫ����" << Line_Num << "����" << abs(Pos1 - Pos2) << "վ" << endl;
	return abs(Pos1 - Pos2);
}