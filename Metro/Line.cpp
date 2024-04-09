#include"Line.h"
Line::Line()
{
	this->Read_Info(M1);
	this->Read_Info(M2);
	this->Read_Info(M3);
	this->Read_Info(M4);
	this->Read_Info(M5);
	this->Read_Info(M7);
	this->Read_Info(M10);
	this->Read_Info(S1);
	this->Read_Info(S3);
	this->Read_Info(S6);
	this->Read_Info(S7);
	this->Read_Info(S8);
	this->Read_Info(S9);
	this->Read_Passenger();
	this->Read_Time();
}
void Line::Read_Info(string filename)
{
	MetroLine ML;
	ifstream ifs;
	ifs.open(filename, ios::in);
	int Line_Num;//地铁线路号
	int Distance;//与第一站的距离号
	string Name;//地铁站名
	ifs >> Line_Num;
	ML.m_ID = Line_Num;
	while (ifs >> Distance && ifs >> Name)
	{
		ML.m.insert(make_pair(Distance, Name)); //ML中的map容器插入数据
	}
	ifs.close();
	this->v.push_back(ML); //将ML放入地铁信息容器v中
}
void Line::Save_Info(int Line_Num)
{
	string filename;
	switch (Line_Num)
	{
	case 1:filename = M1; break;
	case 2:filename = M2; break;
	case 3:filename = M3; break;
	case 4:filename = M4; break;
	case 5:filename = M5; break;
	case 7:filename = M7; break;
	case 10:filename = M10; break;
	case 101:filename = S1; break;
	case 103:filename = S3; break;
	case 106:filename = S6; break;
	case 107:filename = S7; break;
	case 108:filename = S8; break;
	case 109:filename = S9; break;
	default:
		break;
	}
	ofstream ofs;
	ofs.open(filename, ios::out);
	ofs << Line_Num << endl;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		if (it->m_ID != Line_Num)
		{
			continue;
		}
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			ofs << mt->first << " " << mt->second << endl;
		}
	}
	ofs.close();
}
void Line::Read_Passenger()
{
	Users uu;
	ifstream ifs;
	ifs.open(Info, ios::in);
	string ID;
	string Name;
	string Key;
	double Money;
	while (ifs >> ID && ifs >> Name && ifs >> Key && ifs >> Money)
	{
		uu.m_ID = ID;
		uu.m_Name = Name;
		uu.m_Money = Money;
		uu.m_Key = Key;
		uu.o_ID = "0";
		uu.o_Name = "无";
		uu.m_Type = 0;
		uu.m_Turnover = 0;
		this->u.push_back(uu); //一行信息读完放入用户信息容器u中
	}
	ifs.close();
}
void Line::Save_Passenger()
{
	ofstream ofs;
	ofs.open(Info, ios::out);
	for (vector<Users>::iterator it = this->u.begin(); it != this->u.end(); it++)
	{
		ofs << it->m_ID << " "
			<< it->m_Name << " "
			<< it->m_Key << " "
			<< it->m_Money << endl;
	}
	ofs.close();
}
void Line::Save_Water(string ID)
{
	ofstream ofs;
	ofs.open(Water, ios::app);
	for (vector<Users>::iterator it = this->u.begin(); it != this->u.end(); it++)
	{
		if (it->m_ID != ID)
		{
			continue;
		}
		ofs << it->m_ID << " "
			<< it->o_ID << " "
			<< it->o_Name << " "
			<< it->m_Turnover << " "
			<< it->m_Type << endl;
	}
	ofs.close();
}
void Line::Admin_Login()
{
	system("cls");
	string ID;
	char Pw[16];
	string PassWord;
	for (int i = 0; i < 16; i++)
	{
		Pw[i] = '\0';
	}
	int flag = 0;
	while (true)
	{
		ID = this->ID_Key(Pw);
		PassWord = Pw[0]; //将输入的密码转移至string类型的PassWord中
		for (int i = 1; i < strlen(Pw); i++)
		{
			PassWord += Pw[i];
		}
		if (ID == "admin" && PassWord == "Yin5161575")
		{
			return;
		}
		else
		{
			cout << endl << "账号或密码输入错误！" << endl << endl;
			system("pause");
			system("cls");
		}
		flag++;
		if (flag == 3)
		{
			cout << "输入错误次数过多，即将退出系统！" << endl;
			system("pause");
			exit(1);
		}
	}
}
void Line::Admin_Menu()
{
	cout << "******************************" << endl;
	cout << "**                          **" << endl;
	cout << "**        1.添加车站        **" << endl;
	cout << "**                          **" << endl;
	cout << "**        2.删除车站        **" << endl;
	cout << "**                          **" << endl;
	cout << "**      3.修改车站信息      **" << endl;
	cout << "**                          **" << endl;
	cout << "**      4.查看车站信息      **" << endl;
	cout << "**                          **" << endl;
	cout << "**       5.返回上一级       **" << endl;
	cout << "**                          **" << endl;
	cout << "******************************" << endl;
	cout << "                              " << endl;
	cout << "请输入您的选择：";
}
void Line::Add_Station()
{
	system("cls");
	int select = 0;
	string Name;
	int Dis = 0;
	cout << "请输入车站名称：";
	cin >> Name;
	cout << "101、S1号线  103、S3号线  106、S6号线  107、S7号线  108、S8号线  109、S9号线" << endl;
	cout << "请输入您需要添加的车站所在路线(如果是换乘站请重复此操作)：";
	cin >> select;
	cout << "请输入与首站的距离：";
	cin >> Dis;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		if (it->m_ID != select) //如果线路不是当前容器m_ID，跳过当前循环，继续寻找线路
		{
			continue;
		}
		it->m.insert(make_pair(Dis, Name));
	}
	this->Save_Info(select);
	cout << "添加成功！" << endl;
	system("pause");
}
void Line::Delete_Station()
{
	system("cls");
	string Name;
	cout << "请输入需要删除的车站名称：";
	cin >> Name;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			if (Name == mt->second) //从容器中寻找对应的车站名称
			{
				it->m.erase(mt);
				this->Save_Info(it->m_ID);
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
		}
	}
	cout << "没有“" << Name << "”站，删除失败！" << endl;
	system("pause");
}
void Line::Correct_Station()
{
	system("cls");
	string Name;
	int flag = 0;
	cout << "请输入需要修改的车站名称：";
	cin >> Name;
	string N_Name;
	cout << "请输入新的车站名称：";
	cin >> N_Name;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			if (Name == mt->second) //从容器中寻找对应的车站名称
			{
				mt->second = N_Name;
				flag++;
				this->Save_Info(it->m_ID);
			}
		}
	}
	if (flag)
	{
		cout << "修改成功！" << endl;
		system("pause");
	}
	else
	{
		cout << "没有“" << Name << "”站，修改失败！" << endl;
		system("pause");
	}
}
void Line::Look_Info()
{
	system("cls");
	int select = 0;
	cout << "请输入需要查看的线路：";
	cin >> select;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		if (it->m_ID != select)
		{
			continue;
		}
		else
		{
			it->Show_Info(); //直接调用MetroLine类中的函数显示信息
			system("pause");
		}
	}
}
void Line::Find_Line(string Name, int* p) //指针p中存放的是车站所在的所有线路
{
	for (int i = 0; i < 11; i++) //初始化将p置零
	{
		*(p + i) = 0;
	}
	int flag = 0;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			if (mt->second == Name)
			{
				p[flag] = it->m_ID; //找到一条线路中有Name站，存放至指针p中
				flag++;
			}
		}
	}
	p[10] = flag; //flag表示总共有flag条线路有Name站
}
void Line::No_Change(string Name1, string Name2, int* p) //指针p用来存放多条线路共有Name1站和Name2站，例如南京站和南京南站同在1号线和3号线
{
	for (int i = 0; i < 11; i++)
	{
		*(p + i) = 0;
	}
	int flag = 0;
	int Line1[11] = { 0 };
	int Line2[11] = { 0 };
	this->Find_Line(Name1, Line1); //Line1为Name1站所在的线路
	this->Find_Line(Name2, Line2); //Line2为Name2站所在的线路
	for (int i = 0; i < Line1[10]; i++)
	{
		for (int j = 0; j < Line2[10]; j++)
		{
			if (Line1[i] == Line2[j])
			{
				*(p + flag) = Line1[i]; //线路相同则不需要换乘，返回该线路
				flag++;
			}
		}
	}
	p[10] = flag; //flag如果为0，则两个车站不在同一条线路，需要换乘
}
string Line::ID_Key(char* Pw)
{
	string ID;
	int Key = 0;
	int num = 0;
	for (int i = 0; i < 16; i++)
	{
		Pw[i] = '\0';
	}
	cout << "请输入您的账号：";
	cin >> ID;
	cout << "请输入您的密码：";
	while (true)
	{
		Key = _getch();
		if ((Key >= 48 && Key <= 57) || (Key >= 65 && Key <= 90) || (Key >= 97 && Key <= 122)) //键入范围在数字和字母内输出*
		{
			Pw[num] = (char)Key;
			cout << "*";
			num++;
		}
		else if (Key == 8) //键入退格Backspace
		{
			if (num != 0)
			{
				system("cls");
				cout << "请输入您的账号：" << ID << endl << "请输入您的密码：";
				for (int i = 0; i < num - 1; i++)
				{
					cout << "*";
				}
				Pw[num - 1] = '\0';
				num--;
			}
		}
		else if (Key == 13) //键入回车Enter
		{
			break;
		}
	}
	return ID;
}
int Line::Find_Transfer(int ID, string* p) //返回ID号线换乘站个数，指针p存放所有换乘站
{
	for (int i = 0; i < 30; i++)
	{
		*(p + i) = "\0";
	}
	MetroLine line; //ID所在线路
	int flag = 0;
	int index = 0;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++) //从容器v中寻找路线ID
	{
		if (it->m_ID == ID)
		{
			line = *it;
			break;
		}
	}
	for (map<int, string>::iterator mt1 = line.m.begin(); mt1 != line.m.end(); mt1++) //最外循环，遍历ID号线所有车站
	{
		for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++) //遍历除ID号线之外所有线路
		{
			index = 0;
			if (it->m_ID == ID) //线路相同则跳出当前循环
			{
				continue;
			}
			for (map<int, string>::iterator mt2 = it->m.begin(); mt2 != it->m.end(); mt2++) //遍历某一线路中所有车站
			{
				if (mt1->second == mt2->second) //在2条线路中均有同一站
				{
					for (int i = 0; i < flag; i++)
					{
						if (p[i] == mt1->second)
						{
							index++; //index防止重复记入换乘车站
							break;
						}
					}
					if (index)
					{
						break;
					}
					p[flag] = mt1->second;
					flag++;
					break;
				}
			}
		}
	}
	return flag; //flag是某一条线路的换乘车站个数
}
string Line::Passenger_Login()
{
	system("cls");
	string ID;
	int Key = 0;
	char Pw[16];
	string PassWord;
	for (int i = 0; i < 16; i++)
	{
		Pw[i] = '\0';
	}
	int flag = 0;
	while (true)
	{
		ID = this->ID_Key(Pw);
		PassWord = Pw[0];
		for (int i = 1; i < strlen(Pw); i++)
		{
			PassWord += Pw[i];
		}
		for (vector<Users>::iterator it = this->u.begin(); it != this->u.end(); it++)
		{
			if (it->m_ID == ID)
			{
				if (it->m_Key == PassWord)
				{
					return ID;
				}
			}
		}
		flag++;
		if (flag == 3)
		{
			cout << "输入错误次数过多，即将退出系统！" << endl;
			system("pause");
			exit(1);
		}
		cout << endl << "账号或密码输入错误！" << endl << endl;
		system("pause");
		system("cls");
	}
}
void Line::Passenger_Menu()
{
	cout << "******************************" << endl;
	cout << "**                          **" << endl;
	cout << "**        1.购买车票        **" << endl;
	cout << "**                          **" << endl;
	cout << "**        2.查询信息        **" << endl;
	cout << "**                          **" << endl;
	cout << "**      3.查询乘车记录      **" << endl;
	cout << "**                          **" << endl;
	cout << "**       4.返回上一级       **" << endl;
	cout << "**                          **" << endl;
	cout << "******************************" << endl;
	cout << "                              " << endl;
	cout << "请输入您的选择：";
}
void Line::Passenger()
{
	system("cls");
	string Name1;
	string Name2;
	cout << "请输入起点站：";
	cin >> Name1; //Name1为起点站
	cout << "请输入终点站：";
	cin >> Name2; //Name2为终点站
	int temp = 0; //错误标志符
	int Min_Station_Num = 0; //记录最小站距
	int Station_Num = 0; //站间距
	int Line_Num[11] = { 0 }; //存放两车站所在的相同线路
	this->No_Change(Name1, Name2, Line_Num); //判断是否在同一条线路上，若在同一条线路，则Line_Num数组中存放该线路，不在则Line_Num[10]为0
	if (Line_Num[10]) //两车站在同一线路上，不需要换乘
	{
		for (int i = 0; i < Line_Num[10]; i++) //循环所在多条线路（目前仅有南京站和南京南站同处1、3号线）
		{
			for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
			{
				if (it->m_ID != Line_Num[i]) //找到所在的相同线路
				{
					continue;
				}
				Station_Num = it->Take_Train(Name1, Name2); //MetroLine类内函数，计算两站之间的站间距
			}
		}
		system("pause");
	}
	else //两车站不在同一线路上，需要换乘
	{
		string transfer_station[30]; //存放同一条线路的所有换乘车站
		string transfer_station2[30]; //存放二次换乘线路的换乘车站
		for (int i = 0; i < 30; i++)
		{
			transfer_station[i] = "\0";
			transfer_station2[i] = "\0";
		}
		int Line1[11] = { 0 }; //存放Name1站所在的线路
		//固定Name2站，从Name1站出发
		this->Find_Line(Name1, Line1); //寻找Name1站所在的线路
		for (int i = 0; i < Line1[10]; i++) //一次换乘，Line1[i]（除了i = 10）是线路号
		{
			Station_Num = 0;
			int flag = this->Find_Transfer(Line1[i], transfer_station); //寻找Name1站所在线路所有的换乘站，flag为换乘站数量，transfer_station存放换乘站名称
			multimap<int, string> TransferStation2; //存放Name1站所在线路中的换乘站以及其所在线路
			int TransferStationLine[11] = { 0 };
			for (int j = 0; j < flag; j++)
			{
				this->Find_Line(transfer_station[j], TransferStationLine);
				for (int m = 0; m < TransferStationLine[10]; m++)
				{
					if (TransferStationLine[m] == Line1[i] || transfer_station[j] == Name1)
					{
						continue;
					}
					TransferStation2.insert(make_pair(TransferStationLine[m], transfer_station[j]));
				}
			}
			for (int j = 0; j < flag; j++)
			{
				Station_Num = 0;
				this->No_Change(transfer_station[j], Name2, Line_Num); //判断换乘站到目的地是否需要换乘
				if (Line_Num[10]) //只需要一次换乘
				{
					for (int k = 0; k < Line_Num[k]; k++)
					{
						Station_Num = 0;
						cout << "需要换乘1次！" << endl;
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line1[i]) //计算Name1站到换乘站的站间距
							{
								continue;
							}
							Station_Num += it->Take_Train(Name1, transfer_station[j]);
						}
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line_Num[k]) //计算换乘站到Name2站的站间距
							{
								continue;
							}
							Station_Num += it->Take_Train(transfer_station[j], Name2);
							if (temp == 0)
							{
								Min_Station_Num = Station_Num;
							}
							temp++;
							if (Min_Station_Num > Station_Num)
							{
								Min_Station_Num = Station_Num;
							}
							cout << "总计需要乘坐" << Station_Num << "站" << endl << endl;
						}
					}
				}
				else
				{
					for (multimap<int, string>::iterator it = TransferStation2.begin(); it != TransferStation2.end(); it++)
					{
						if (it->second == transfer_station[j])
						{
							int flag2 = this->Find_Transfer(it->first, transfer_station2);
							for (int n = 0; n < flag2; n++)
							{
								Station_Num = 0;
								this->No_Change(transfer_station2[n], Name2, Line_Num);
								if (Line_Num[10])
								{
									for (int r = 0; r < Line_Num[r]; r++)
									{
										Station_Num = 0;
										cout << "需要换乘2次！" << endl;
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line1[i]) //计算Name1站到换乘站1的站间距
											{
												continue;
											}
											Station_Num += mt->Take_Train(Name1, transfer_station[j]);
										}
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != it->first)
											{
												continue;
											}
											Station_Num += mt->Take_Train(transfer_station[j], transfer_station2[n]);
										}
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line_Num[r])
											{
												continue;
											}
											Station_Num += mt->Take_Train(transfer_station2[n], Name2);
											if (temp == 0)
											{
												Min_Station_Num = Station_Num;
											}
											temp++;
											if (Min_Station_Num > Station_Num)
											{
												Min_Station_Num = Station_Num;
											}
											cout << "总计需要乘坐" << Station_Num << "站" << endl << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (Min_Station_Num == 0)
		{
			cout << "您的输入有误！" << endl;
			system("pause");
			return;
		}
		cout << "最少需要乘坐" << Min_Station_Num << "站" << endl;
		system("pause");
		return;
	}
}
void Line::Passenger_Buy_Ticket(string ID)
{
	system("cls");
	string Name1;
	string Name2;
	Times tt;
	int trans = 0; //记录中转次数
	int No_Trans = 0; //不用中转的线路
	int One_Trans_1 = 0;
	int One_Trans_2 = 0; //一次中转的线路
	int Two_Trans_1 = 0;
	int Two_Trans_2 = 0;
	int Two_Trans_3 = 0; //两次中转的线路
	string TransferStation_1; //记录中转车站
	string TransferStation_2_1;
	string TransferStation_2_2; //记录2个中转车站
	cout << "请输入起点站：";
	cin >> Name1;
	cout << "请输入终点站：";
	cin >> Name2;
	int Station_Num = 0; //记录站距
	int Min_Station_Num = 0; //记录最小站距
	int Line_Num[11] = { 0 };
	int temp = 0; //错误标识符
	this->No_Change(Name1, Name2, Line_Num);
	if (Line_Num[10])
	{
		for (int i = 0; i < Line_Num[10]; i++)
		{
			for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
			{
				if (it->m_ID != Line_Num[i])
				{
					continue;
				}
				Station_Num = it->Take_Train(Name1, Name2);
				if (temp == 0)
				{
					No_Trans = Line_Num[i];
					trans = 0;
					Min_Station_Num = Station_Num;
				}
				temp++;
				cout << "需要消费" << this->Cost_Money(Station_Num) << "元" << endl;
				if (Min_Station_Num > Station_Num)
				{
					No_Trans = Line_Num[i];
					trans = 0;
					Min_Station_Num = Station_Num;
				}
			}
		}
	}
	else
	{
		string transfer_station[30];
		string transfer_station2[30]; //存放二次换乘线路的换乘车站
		for (int i = 0; i < 30; i++)
		{
			transfer_station[i] = "\0";
			transfer_station2[i] = "\0";
		}
		int Line1[11] = { 0 };
		//固定Name2站，从Name1站出发
		this->Find_Line(Name1, Line1); //寻找Name1站所在的线路
		for (int i = 0; i < Line1[10]; i++) //一次换乘
		{
			Station_Num = 0;
			int flag = this->Find_Transfer(Line1[i], transfer_station); //寻找Name1站所在线路所有的换乘站
			multimap<int, string> TransferStation2; //存放Name1站所在线路中的换乘站以及其所在线路
			int TransferStationLine[11] = { 0 };
			for (int j = 0; j < flag; j++)
			{
				this->Find_Line(transfer_station[j], TransferStationLine);
				for (int m = 0; m < TransferStationLine[10]; m++)
				{
					if (TransferStationLine[m] == Line1[i] || transfer_station[j] == Name1)
					{
						continue;
					}
					TransferStation2.insert(make_pair(TransferStationLine[m], transfer_station[j]));
				}
			}
			for (int j = 0; j < flag; j++)
			{
				Station_Num = 0;
				this->No_Change(transfer_station[j], Name2, Line_Num); //判断换乘站到目的地是否需要换乘
				if (Line_Num[10]) //只需要一次换乘
				{
					for (int k = 0; k < Line_Num[k]; k++)
					{
						Station_Num = 0;
						cout << "需要换乘1次！" << endl;
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line1[i])
							{
								continue;
							}
							Station_Num += it->Take_Train(Name1, transfer_station[j]);
						}
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line_Num[k])
							{
								continue;
							}
							Station_Num += it->Take_Train(transfer_station[j], Name2);
							if (temp == 0)
							{
								One_Trans_1 = Line1[i];
								One_Trans_2 = Line_Num[k];
								trans = 1;
								Min_Station_Num = Station_Num;
								TransferStation_1 = transfer_station[j];
							}
							temp++;
							if (Min_Station_Num > Station_Num)
							{
								One_Trans_1 = Line1[i];
								One_Trans_2 = Line_Num[k];
								trans = 1;
								Min_Station_Num = Station_Num;
								TransferStation_1 = transfer_station[j];
							}
							cout << "总计需要乘坐" << Station_Num << "站" << endl << endl;
						}
					}
				}
				else
				{
					for (multimap<int, string>::iterator it = TransferStation2.begin(); it != TransferStation2.end(); it++)
					{
						if (it->second == transfer_station[j])
						{
							int flag2 = this->Find_Transfer(it->first, transfer_station2);
							for (int n = 0; n < flag2; n++)
							{
								Station_Num = 0;
								this->No_Change(transfer_station2[n], Name2, Line_Num);
								if (Line_Num[10])
								{
									for (int r = 0; r < Line_Num[r]; r++)
									{
										Station_Num = 0;
										cout << "需要换乘2次！" << endl;
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line1[i]) //计算Name1站到换乘站1的站间距
											{
												continue;
											}
											Station_Num += mt->Take_Train(Name1, transfer_station[j]);
										}
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != it->first)
											{
												continue;
											}
											Station_Num += mt->Take_Train(transfer_station[j], transfer_station2[n]);
										}
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line_Num[r])
											{
												continue;
											}
											Station_Num += mt->Take_Train(transfer_station2[n], Name2);
											if (temp == 0)
											{
												Two_Trans_1 = Line1[i];
												Two_Trans_2 = it->first;
												Two_Trans_3 = Line_Num[r];
												trans = 2;
												Min_Station_Num = Station_Num;
												TransferStation_2_1 = transfer_station[j];
												TransferStation_2_2 = transfer_station2[n];
											}
											temp++;
											if (Min_Station_Num > Station_Num)
											{
												Two_Trans_1 = Line1[i];
												Two_Trans_2 = it->first;
												Two_Trans_3 = Line_Num[r];
												trans = 2;
												Min_Station_Num = Station_Num;
												TransferStation_2_1 = transfer_station[j];
												TransferStation_2_2 = transfer_station2[n];
											}
											cout << "总计需要乘坐" << Station_Num << "站" << endl << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (temp == 0)
	{
		cout << "您的输入有误！" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "最小站距为" << Min_Station_Num << "站，需要消费" << this->Cost_Money(Min_Station_Num) << "元" << endl;
	for (vector<Users>::iterator it = this->u.begin(); it != this->u.end(); it++)
	{
		if (it->m_ID != ID)
		{
			continue;
		}
		it->m_Money -= Cost_Money(Min_Station_Num);
		it->m_Turnover = -Cost_Money(Min_Station_Num);
		it->m_Type = 4;
		it->o_ID = "0";
		it->o_Name = "南京地铁";
		this->Save_Passenger();
		this->Save_Water(ID);
		break;
	}
	time_t nowtime;
	nowtime = time(NULL);
	struct tm* local;
	local = localtime(&nowtime);
	tt.m_ID = ID;
	tt.m_year = local->tm_year + 1900;
	tt.m_month = local->tm_mon + 1;
	tt.m_day = local->tm_mday;
	tt.m_hour = local->tm_hour;
	tt.m_min = local->tm_min;
	tt.m_sec = local->tm_sec;
	if (trans == 0)
	{
		tt.m_trans = 0;
		tt.m_MetroNum.push_back(No_Trans);
		tt.m_station.push_back(Name1);
		tt.m_station.push_back(Name2);
	}
	else if (trans == 1)
	{
		tt.m_trans = 1;
		tt.m_MetroNum.push_back(One_Trans_1);
		tt.m_MetroNum.push_back(One_Trans_2);
		tt.m_station.push_back(Name1);
		tt.m_station.push_back(TransferStation_1);
		tt.m_station.push_back(Name2);
	}
	else if (trans == 2)
	{
		tt.m_trans = 2;
		tt.m_MetroNum.push_back(Two_Trans_1);
		tt.m_MetroNum.push_back(Two_Trans_2);
		tt.m_MetroNum.push_back(Two_Trans_3);
		tt.m_station.push_back(Name1);
		tt.m_station.push_back(TransferStation_2_1);
		tt.m_station.push_back(TransferStation_2_2);
		tt.m_station.push_back(Name2);
	}
	this->t.push_back(tt);
	this->Save_Time();
	tt.m_station.clear();
	tt.m_MetroNum.clear();
	system("pause");
}
int Line::Cost_Money(int Distance)
{
	if (Distance <= 3)
	{
		return 2;
	}
	else if (Distance > 3 && Distance <= 7)
	{
		return 3;
	}
	else if (Distance > 7 && Distance <= 13)
	{
		return 4;
	}
	else if (Distance > 13 && Distance <= 20)
	{
		return 5;
	}
	else if (Distance > 20 && Distance <= 28)
	{
		return 6;
	}
	else if (Distance > 28 && Distance <= 40)
	{
		return 7;
	}
	else
	{
		return 8;
	}
}
void Line::Read_Time()
{
	Times tt;
	ifstream ifs;
	ifs.open(Time, ios::in);
	string ID;
	int year, month, day, hour, min, sec, trans;
	int MetroNum[3] = { 0 };
	string station[4] = { "\0" };
	while (ifs >> ID && ifs >> year && ifs >> month && ifs >> day && ifs >> hour && ifs >> min && ifs >> sec && ifs >> trans)
	{
		tt.m_ID = ID;
		tt.m_year = year;
		tt.m_month = month;
		tt.m_day = day;
		tt.m_hour = hour;
		tt.m_min = min;
		tt.m_sec = sec;
		tt.m_trans = trans;
		if (trans == 0)
		{
			while (ifs >> MetroNum[0] && ifs >> station[0] && ifs >> station[1])
			{
				tt.m_MetroNum.push_back(MetroNum[0]);
				tt.m_station.push_back(station[0]);
				tt.m_station.push_back(station[1]);
				break;
			}
		}
		else if (trans == 1)
		{
			while (ifs >> MetroNum[0] && ifs >> MetroNum[1] && ifs >> station[0] && ifs >> station[1] && ifs >> station[2])
			{
				tt.m_MetroNum.push_back(MetroNum[0]);
				tt.m_MetroNum.push_back(MetroNum[1]);
				tt.m_station.push_back(station[0]);
				tt.m_station.push_back(station[1]);
				tt.m_station.push_back(station[2]);
				break;
			}
		}
		else if (trans == 2)
		{
			while (ifs >> MetroNum[0] && ifs >> MetroNum[1] && ifs >> MetroNum[2] && ifs >> station[0] && ifs >> station[1] && ifs >> station[2] && ifs >> station[3])
			{
				tt.m_MetroNum.push_back(MetroNum[0]);
				tt.m_MetroNum.push_back(MetroNum[1]);
				tt.m_MetroNum.push_back(MetroNum[2]);
				tt.m_station.push_back(station[0]);
				tt.m_station.push_back(station[1]);
				tt.m_station.push_back(station[2]);
				tt.m_station.push_back(station[3]);
				break;
			}
		}
		this->t.push_back(tt);
		tt.m_MetroNum.clear();
		tt.m_station.clear();
	}
	ifs.close();
}
void Line::Save_Time()
{
	ofstream ofs;
	ofs.open(Time, ios::out);
	for (vector<Times>::iterator it = this->t.begin(); it != this->t.end(); it++)
	{
		ofs << it->m_ID << " "
			<< it->m_year << " "
			<< it->m_month << " "
			<< it->m_day << " "
			<< it->m_hour << " "
			<< it->m_min << " "
			<< it->m_sec << " "
			<< it->m_trans << " ";
		for (vector<int>::iterator mt = it->m_MetroNum.begin(); mt != it->m_MetroNum.end(); mt++)
		{
			ofs << *mt << " ";
		}
		for (int i = 0; i < it->m_station.size(); i++)
		{
			if (i + 1 == it->m_station.size())
			{
				ofs << it->m_station[i] << endl;
			}
			else 
			{
				ofs << it->m_station[i] << " ";
			}
		}
	}
	ofs.close();
}
void Line::Check_Time(string ID)
{
	system("cls");
	for (vector<Times>::iterator it = this->t.begin(); it != this->t.end(); it++)
	{
		if (ID != it->m_ID)
		{
			continue;
		}
		it->Show_Info();
	}
	system("pause");
}