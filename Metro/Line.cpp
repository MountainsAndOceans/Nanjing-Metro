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
	int Line_Num;//������·��
	int Distance;//���һվ�ľ����
	string Name;//����վ��
	ifs >> Line_Num;
	ML.m_ID = Line_Num;
	while (ifs >> Distance && ifs >> Name)
	{
		ML.m.insert(make_pair(Distance, Name)); //ML�е�map������������
	}
	ifs.close();
	this->v.push_back(ML); //��ML���������Ϣ����v��
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
		uu.o_Name = "��";
		uu.m_Type = 0;
		uu.m_Turnover = 0;
		this->u.push_back(uu); //һ����Ϣ��������û���Ϣ����u��
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
		PassWord = Pw[0]; //�����������ת����string���͵�PassWord��
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
			cout << endl << "�˺Ż������������" << endl << endl;
			system("pause");
			system("cls");
		}
		flag++;
		if (flag == 3)
		{
			cout << "�������������࣬�����˳�ϵͳ��" << endl;
			system("pause");
			exit(1);
		}
	}
}
void Line::Admin_Menu()
{
	cout << "******************************" << endl;
	cout << "**                          **" << endl;
	cout << "**        1.��ӳ�վ        **" << endl;
	cout << "**                          **" << endl;
	cout << "**        2.ɾ����վ        **" << endl;
	cout << "**                          **" << endl;
	cout << "**      3.�޸ĳ�վ��Ϣ      **" << endl;
	cout << "**                          **" << endl;
	cout << "**      4.�鿴��վ��Ϣ      **" << endl;
	cout << "**                          **" << endl;
	cout << "**       5.������һ��       **" << endl;
	cout << "**                          **" << endl;
	cout << "******************************" << endl;
	cout << "                              " << endl;
	cout << "����������ѡ��";
}
void Line::Add_Station()
{
	system("cls");
	int select = 0;
	string Name;
	int Dis = 0;
	cout << "�����복վ���ƣ�";
	cin >> Name;
	cout << "101��S1����  103��S3����  106��S6����  107��S7����  108��S8����  109��S9����" << endl;
	cout << "����������Ҫ��ӵĳ�վ����·��(����ǻ���վ���ظ��˲���)��";
	cin >> select;
	cout << "����������վ�ľ��룺";
	cin >> Dis;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		if (it->m_ID != select) //�����·���ǵ�ǰ����m_ID��������ǰѭ��������Ѱ����·
		{
			continue;
		}
		it->m.insert(make_pair(Dis, Name));
	}
	this->Save_Info(select);
	cout << "��ӳɹ���" << endl;
	system("pause");
}
void Line::Delete_Station()
{
	system("cls");
	string Name;
	cout << "��������Ҫɾ���ĳ�վ���ƣ�";
	cin >> Name;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			if (Name == mt->second) //��������Ѱ�Ҷ�Ӧ�ĳ�վ����
			{
				it->m.erase(mt);
				this->Save_Info(it->m_ID);
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
		}
	}
	cout << "û�С�" << Name << "��վ��ɾ��ʧ�ܣ�" << endl;
	system("pause");
}
void Line::Correct_Station()
{
	system("cls");
	string Name;
	int flag = 0;
	cout << "��������Ҫ�޸ĵĳ�վ���ƣ�";
	cin >> Name;
	string N_Name;
	cout << "�������µĳ�վ���ƣ�";
	cin >> N_Name;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		for (map<int, string>::iterator mt = it->m.begin(); mt != it->m.end(); mt++)
		{
			if (Name == mt->second) //��������Ѱ�Ҷ�Ӧ�ĳ�վ����
			{
				mt->second = N_Name;
				flag++;
				this->Save_Info(it->m_ID);
			}
		}
	}
	if (flag)
	{
		cout << "�޸ĳɹ���" << endl;
		system("pause");
	}
	else
	{
		cout << "û�С�" << Name << "��վ���޸�ʧ�ܣ�" << endl;
		system("pause");
	}
}
void Line::Look_Info()
{
	system("cls");
	int select = 0;
	cout << "��������Ҫ�鿴����·��";
	cin >> select;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
	{
		if (it->m_ID != select)
		{
			continue;
		}
		else
		{
			it->Show_Info(); //ֱ�ӵ���MetroLine���еĺ�����ʾ��Ϣ
			system("pause");
		}
	}
}
void Line::Find_Line(string Name, int* p) //ָ��p�д�ŵ��ǳ�վ���ڵ�������·
{
	for (int i = 0; i < 11; i++) //��ʼ����p����
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
				p[flag] = it->m_ID; //�ҵ�һ����·����Nameվ�������ָ��p��
				flag++;
			}
		}
	}
	p[10] = flag; //flag��ʾ�ܹ���flag����·��Nameվ
}
void Line::No_Change(string Name1, string Name2, int* p) //ָ��p������Ŷ�����·����Name1վ��Name2վ�������Ͼ�վ���Ͼ���վͬ��1���ߺ�3����
{
	for (int i = 0; i < 11; i++)
	{
		*(p + i) = 0;
	}
	int flag = 0;
	int Line1[11] = { 0 };
	int Line2[11] = { 0 };
	this->Find_Line(Name1, Line1); //Line1ΪName1վ���ڵ���·
	this->Find_Line(Name2, Line2); //Line2ΪName2վ���ڵ���·
	for (int i = 0; i < Line1[10]; i++)
	{
		for (int j = 0; j < Line2[10]; j++)
		{
			if (Line1[i] == Line2[j])
			{
				*(p + flag) = Line1[i]; //��·��ͬ����Ҫ���ˣ����ظ���·
				flag++;
			}
		}
	}
	p[10] = flag; //flag���Ϊ0����������վ����ͬһ����·����Ҫ����
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
	cout << "�����������˺ţ�";
	cin >> ID;
	cout << "�������������룺";
	while (true)
	{
		Key = _getch();
		if ((Key >= 48 && Key <= 57) || (Key >= 65 && Key <= 90) || (Key >= 97 && Key <= 122)) //���뷶Χ�����ֺ���ĸ�����*
		{
			Pw[num] = (char)Key;
			cout << "*";
			num++;
		}
		else if (Key == 8) //�����˸�Backspace
		{
			if (num != 0)
			{
				system("cls");
				cout << "�����������˺ţ�" << ID << endl << "�������������룺";
				for (int i = 0; i < num - 1; i++)
				{
					cout << "*";
				}
				Pw[num - 1] = '\0';
				num--;
			}
		}
		else if (Key == 13) //����س�Enter
		{
			break;
		}
	}
	return ID;
}
int Line::Find_Transfer(int ID, string* p) //����ID���߻���վ������ָ��p������л���վ
{
	for (int i = 0; i < 30; i++)
	{
		*(p + i) = "\0";
	}
	MetroLine line; //ID������·
	int flag = 0;
	int index = 0;
	for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++) //������v��Ѱ��·��ID
	{
		if (it->m_ID == ID)
		{
			line = *it;
			break;
		}
	}
	for (map<int, string>::iterator mt1 = line.m.begin(); mt1 != line.m.end(); mt1++) //����ѭ��������ID�������г�վ
	{
		for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++) //������ID����֮��������·
		{
			index = 0;
			if (it->m_ID == ID) //��·��ͬ��������ǰѭ��
			{
				continue;
			}
			for (map<int, string>::iterator mt2 = it->m.begin(); mt2 != it->m.end(); mt2++) //����ĳһ��·�����г�վ
			{
				if (mt1->second == mt2->second) //��2����·�о���ͬһվ
				{
					for (int i = 0; i < flag; i++)
					{
						if (p[i] == mt1->second)
						{
							index++; //index��ֹ�ظ����뻻�˳�վ
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
	return flag; //flag��ĳһ����·�Ļ��˳�վ����
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
			cout << "�������������࣬�����˳�ϵͳ��" << endl;
			system("pause");
			exit(1);
		}
		cout << endl << "�˺Ż������������" << endl << endl;
		system("pause");
		system("cls");
	}
}
void Line::Passenger_Menu()
{
	cout << "******************************" << endl;
	cout << "**                          **" << endl;
	cout << "**        1.����Ʊ        **" << endl;
	cout << "**                          **" << endl;
	cout << "**        2.��ѯ��Ϣ        **" << endl;
	cout << "**                          **" << endl;
	cout << "**      3.��ѯ�˳���¼      **" << endl;
	cout << "**                          **" << endl;
	cout << "**       4.������һ��       **" << endl;
	cout << "**                          **" << endl;
	cout << "******************************" << endl;
	cout << "                              " << endl;
	cout << "����������ѡ��";
}
void Line::Passenger()
{
	system("cls");
	string Name1;
	string Name2;
	cout << "���������վ��";
	cin >> Name1; //Name1Ϊ���վ
	cout << "�������յ�վ��";
	cin >> Name2; //Name2Ϊ�յ�վ
	int temp = 0; //�����־��
	int Min_Station_Num = 0; //��¼��Сվ��
	int Station_Num = 0; //վ���
	int Line_Num[11] = { 0 }; //�������վ���ڵ���ͬ��·
	this->No_Change(Name1, Name2, Line_Num); //�ж��Ƿ���ͬһ����·�ϣ�����ͬһ����·����Line_Num�����д�Ÿ���·��������Line_Num[10]Ϊ0
	if (Line_Num[10]) //����վ��ͬһ��·�ϣ�����Ҫ����
	{
		for (int i = 0; i < Line_Num[10]; i++) //ѭ�����ڶ�����·��Ŀǰ�����Ͼ�վ���Ͼ���վͬ��1��3���ߣ�
		{
			for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
			{
				if (it->m_ID != Line_Num[i]) //�ҵ����ڵ���ͬ��·
				{
					continue;
				}
				Station_Num = it->Take_Train(Name1, Name2); //MetroLine���ں�����������վ֮���վ���
			}
		}
		system("pause");
	}
	else //����վ����ͬһ��·�ϣ���Ҫ����
	{
		string transfer_station[30]; //���ͬһ����·�����л��˳�վ
		string transfer_station2[30]; //��Ŷ��λ�����·�Ļ��˳�վ
		for (int i = 0; i < 30; i++)
		{
			transfer_station[i] = "\0";
			transfer_station2[i] = "\0";
		}
		int Line1[11] = { 0 }; //���Name1վ���ڵ���·
		//�̶�Name2վ����Name1վ����
		this->Find_Line(Name1, Line1); //Ѱ��Name1վ���ڵ���·
		for (int i = 0; i < Line1[10]; i++) //һ�λ��ˣ�Line1[i]������i = 10������·��
		{
			Station_Num = 0;
			int flag = this->Find_Transfer(Line1[i], transfer_station); //Ѱ��Name1վ������·���еĻ���վ��flagΪ����վ������transfer_station��Ż���վ����
			multimap<int, string> TransferStation2; //���Name1վ������·�еĻ���վ�Լ���������·
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
				this->No_Change(transfer_station[j], Name2, Line_Num); //�жϻ���վ��Ŀ�ĵ��Ƿ���Ҫ����
				if (Line_Num[10]) //ֻ��Ҫһ�λ���
				{
					for (int k = 0; k < Line_Num[k]; k++)
					{
						Station_Num = 0;
						cout << "��Ҫ����1�Σ�" << endl;
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line1[i]) //����Name1վ������վ��վ���
							{
								continue;
							}
							Station_Num += it->Take_Train(Name1, transfer_station[j]);
						}
						for (vector<MetroLine>::iterator it = this->v.begin(); it != this->v.end(); it++)
						{
							if (it->m_ID != Line_Num[k]) //���㻻��վ��Name2վ��վ���
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
							cout << "�ܼ���Ҫ����" << Station_Num << "վ" << endl << endl;
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
										cout << "��Ҫ����2�Σ�" << endl;
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line1[i]) //����Name1վ������վ1��վ���
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
											cout << "�ܼ���Ҫ����" << Station_Num << "վ" << endl << endl;
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
			cout << "������������" << endl;
			system("pause");
			return;
		}
		cout << "������Ҫ����" << Min_Station_Num << "վ" << endl;
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
	int trans = 0; //��¼��ת����
	int No_Trans = 0; //������ת����·
	int One_Trans_1 = 0;
	int One_Trans_2 = 0; //һ����ת����·
	int Two_Trans_1 = 0;
	int Two_Trans_2 = 0;
	int Two_Trans_3 = 0; //������ת����·
	string TransferStation_1; //��¼��ת��վ
	string TransferStation_2_1;
	string TransferStation_2_2; //��¼2����ת��վ
	cout << "���������վ��";
	cin >> Name1;
	cout << "�������յ�վ��";
	cin >> Name2;
	int Station_Num = 0; //��¼վ��
	int Min_Station_Num = 0; //��¼��Сվ��
	int Line_Num[11] = { 0 };
	int temp = 0; //�����ʶ��
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
				cout << "��Ҫ����" << this->Cost_Money(Station_Num) << "Ԫ" << endl;
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
		string transfer_station2[30]; //��Ŷ��λ�����·�Ļ��˳�վ
		for (int i = 0; i < 30; i++)
		{
			transfer_station[i] = "\0";
			transfer_station2[i] = "\0";
		}
		int Line1[11] = { 0 };
		//�̶�Name2վ����Name1վ����
		this->Find_Line(Name1, Line1); //Ѱ��Name1վ���ڵ���·
		for (int i = 0; i < Line1[10]; i++) //һ�λ���
		{
			Station_Num = 0;
			int flag = this->Find_Transfer(Line1[i], transfer_station); //Ѱ��Name1վ������·���еĻ���վ
			multimap<int, string> TransferStation2; //���Name1վ������·�еĻ���վ�Լ���������·
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
				this->No_Change(transfer_station[j], Name2, Line_Num); //�жϻ���վ��Ŀ�ĵ��Ƿ���Ҫ����
				if (Line_Num[10]) //ֻ��Ҫһ�λ���
				{
					for (int k = 0; k < Line_Num[k]; k++)
					{
						Station_Num = 0;
						cout << "��Ҫ����1�Σ�" << endl;
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
							cout << "�ܼ���Ҫ����" << Station_Num << "վ" << endl << endl;
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
										cout << "��Ҫ����2�Σ�" << endl;
										for (vector<MetroLine>::iterator mt = this->v.begin(); mt != this->v.end(); mt++)
										{
											if (mt->m_ID != Line1[i]) //����Name1վ������վ1��վ���
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
											cout << "�ܼ���Ҫ����" << Station_Num << "վ" << endl << endl;
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
		cout << "������������" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << "��Сվ��Ϊ" << Min_Station_Num << "վ����Ҫ����" << this->Cost_Money(Min_Station_Num) << "Ԫ" << endl;
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
		it->o_Name = "�Ͼ�����";
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