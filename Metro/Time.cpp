#include"Time.h"
void Times::Show_Info()
{
	if (this->m_trans == 0)
	{
		cout << this->m_year << "年" << this->m_month << "月" << this->m_day << "日" << this->m_hour << "时" << this->m_min << "分" << this->m_sec << "秒，乘坐" 
			<< this->m_MetroNum[0] << "号线，从" << this->m_station[0] << "站，到" << this->m_station[1] << "站" << endl;
	}
	else if (this->m_trans == 1)
	{
		cout << this->m_year << "年" << this->m_month << "月" << this->m_day << "日" << this->m_hour << "时" << this->m_min << "分" << this->m_sec << "秒，乘坐" 
			<< this->m_MetroNum[0] << "号线，从" << this->m_station[0] << "站，到" << this->m_station[1] << "站；乘坐" 
			<< this->m_MetroNum[1] << "号线，从" << this->m_station[1] << "站，到" << this->m_station[2] << "站" << endl;
	}
	else if (this->m_trans == 2)
	{
		cout << this->m_year << "年" << this->m_month << "月" << this->m_day << "日" << this->m_hour << "时" << this->m_min << "分" << this->m_sec << "秒，乘坐"
			<< this->m_MetroNum[0] << "号线，从" << this->m_station[0] << "站，到" << this->m_station[1] << "站；乘坐"
			<< this->m_MetroNum[1] << "号线，从" << this->m_station[1] << "站，到" << this->m_station[2] << "站；乘坐"
			<< this->m_MetroNum[2] << "号线，从" << this->m_station[2] << "站，到" << this->m_station[3] << "站" << endl;
	}
}