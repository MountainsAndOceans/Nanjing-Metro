#include<iostream>
#include"Line.h"
using namespace std;

int main()
{
	Line line;
	int choice = 0;
	int choice1 = 0;
	int choice2 = 0;
	string ID;
FLAG:cout << "1、乘客" << endl << "2、管理员" << endl << "3、退出系统" << endl;
	cout << "请输入您的选择：";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		ID = line.Passenger_Login();
		while (true)
		{
			system("cls");
			line.Passenger_Menu();
			cin >> choice2;
			if (choice2 == 1)
			{
				line.Passenger_Buy_Ticket(ID);
			}
			else if (choice2 == 2)
			{
				line.Passenger();
			}
			else if (choice2 == 3)
			{
				line.Check_Time(ID);
			}
			else if (choice2 == 4)
			{
				system("cls");
				goto FLAG;
			}
		}
		break;
	}
	case 2:
	{
		line.Admin_Login();
		while (true)
		{
			system("cls");
			line.Admin_Menu();
			cin >> choice1;
			if (choice1 == 1)
			{
				line.Add_Station();
			}
			else if (choice1 == 2)
			{
				line.Delete_Station();
			}
			else if (choice1 == 3)
			{
				line.Correct_Station();
			}
			else if (choice1 == 4)
			{
				line.Look_Info();
			}
			else if (choice1 == 5)
			{
				system("cls");
				goto FLAG;
			}
		}
		break;
	}
	default:exit(1);
		break;
	}
	system("pause");
	return 0;
}