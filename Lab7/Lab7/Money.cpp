#include "Money.h"
#include <iostream>
using namespace std;
//���������� �������� ������������
Money& Money::operator=(const Money& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	Rub = t.Rub;
	Kop = t.Kop;
	return *this;
}
//���������� ���������� �������� �������
Money& Money::operator/(int num)
{
	long temp = (Rub * 100 + Kop) / num;
	Money result;
	result.Rub = temp / 100;
	result.Kop = temp % 100;
	return result;
}
Money Money::operator+(const Money& other) 
{
	Money result;
	result.Rub = this->Rub + other.Rub;
	result.Kop = this->Kop + other.Kop;

	// �������� �� ������������ ������
	if (result.Kop >= 100) {
		result.Rub += result.Kop / 100;
		result.Kop %= 100;
	}

	return result;
}


//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& t)
{
	cout << "�����: "; in >> t.Rub;
	cout << "�������: "; in >> t.Kop;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& t)
{
	if (t.Kop < 10)
	{
		return (out << t.Rub << ",0" << t.Kop << " ���");
	}
	else {
		return (out << t.Rub << "," << t.Kop << " ���");
	}
}
