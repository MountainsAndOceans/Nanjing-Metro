#include"MetroLine.h"
void MetroLine::Show_Info()
{
	if (this->m_ID < 100)
	{
		cout << this->m_ID << "号线：" << endl;
	}
	else if (this->m_ID == 101)
	{
		cout << "S1号线" << endl;
	}
	else if (this->m_ID == 103)
	{
		cout << "S3号线" << endl;
	}
	else if (this->m_ID == 106)
	{
		cout << "S6号线" << endl;
	}
	else if (this->m_ID == 107)
	{
		cout << "S7号线" << endl;
	}
	else if (this->m_ID == 108)
	{
		cout << "S8号线" << endl;
	}
	else if (this->m_ID == 109)
	{
		cout << "S9号线" << endl;
	}
	for (map<int, string>::iterator mt = this->m.begin(); mt != this->m.end(); mt++)
	{
		cout << "车站编号：" << mt->first << " 车站名称：" << mt->second << endl;
	}
}
int MetroLine::Take_Train(string Name1, string Name2) //通过map容器的第一个int值来计算站距，形参为两个车站站名
{
	/*定义两个车站的车站编号以计算站距*/
	int Pos1 = 0;
	int Pos2 = 0;
	for (map<int, string>::iterator mt = this->m.begin(); mt != this->m.end(); mt++) //从map容器中找到两个车站的编号
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
	switch (this->m_ID) //确定地铁线路
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
	cout << "从“" << Name1 << "”站到“" << Name2 << "”站需要乘坐" << Line_Num << "号线" << abs(Pos1 - Pos2) << "站" << endl;
	return abs(Pos1 - Pos2);
}