#include"Time.h"
void Times::Show_Info()
{
	if (this->m_trans == 0)
	{
		cout << this->m_year << "��" << this->m_month << "��" << this->m_day << "��" << this->m_hour << "ʱ" << this->m_min << "��" << this->m_sec << "�룬����" 
			<< this->m_MetroNum[0] << "���ߣ���" << this->m_station[0] << "վ����" << this->m_station[1] << "վ" << endl;
	}
	else if (this->m_trans == 1)
	{
		cout << this->m_year << "��" << this->m_month << "��" << this->m_day << "��" << this->m_hour << "ʱ" << this->m_min << "��" << this->m_sec << "�룬����" 
			<< this->m_MetroNum[0] << "���ߣ���" << this->m_station[0] << "վ����" << this->m_station[1] << "վ������" 
			<< this->m_MetroNum[1] << "���ߣ���" << this->m_station[1] << "վ����" << this->m_station[2] << "վ" << endl;
	}
	else if (this->m_trans == 2)
	{
		cout << this->m_year << "��" << this->m_month << "��" << this->m_day << "��" << this->m_hour << "ʱ" << this->m_min << "��" << this->m_sec << "�룬����"
			<< this->m_MetroNum[0] << "���ߣ���" << this->m_station[0] << "վ����" << this->m_station[1] << "վ������"
			<< this->m_MetroNum[1] << "���ߣ���" << this->m_station[1] << "վ����" << this->m_station[2] << "վ������"
			<< this->m_MetroNum[2] << "���ߣ���" << this->m_station[2] << "վ����" << this->m_station[3] << "վ" << endl;
	}
}