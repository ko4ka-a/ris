#include "Money.h"
Money::Money()
{
	rub = 0; kop = 0;
}
Money::Money(long R, int K)
{
	rub = R; kop = K;
}
Money::Money(const Money& m)
{
	rub = m.rub; kop = m.kop;
}
Money Money::operator =(const Money& m)
{
	if (&m == this) return *this;
	rub = m.rub; kop = m.kop;
	return*this;
}
Money::~Money()
{}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& t)
{
	cout << "�����: "; in >> t.rub;
	cout << "�������: "; in >> t.kop;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& t)
{
	if (t.kop < 10)
	{
		return (out << t.rub << ",0" << t.kop << " ���");
	}
	else {
		return (out << t.rub << "," << t.kop << " ���");
	}
}
fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.rub;
	fin >> p.kop;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& p)
{
	fout << p.rub << "\n" << p.kop << "\n";
	return fout;
}
long Money::Get_rub()
{
	return rub;
}
int Money::Get_kop()
{
	return kop;
}
Money Money::operator*(const double num) //���������� ���������� �������� ���������
{
	Money result;
	long totalKop = (rub * 100 + kop) * num;
	result.rub = totalKop / 100;
	result.kop = totalKop % 100;
	return result;
}
bool Money::operator<(const Money& other) const
{
    // ���������� �����, ���� ��� �����, ���������� �������
    if (rub == other.rub)
    {
        return kop < other.kop;
    }
    // ���� ����� ������, ���������� ��������� ��������� ������
    return rub < other.rub;
}

bool Money::operator>(const Money& other) const
{
    // ���������� �����, ���� ��� �����, ���������� �������
    if (rub == other.rub)
    {
        return kop > other.kop;
    }
    // ���� ����� ������, ���������� ��������� ��������� ������
    return rub > other.rub;
}

Money& Money::operator++() // ���������� ����� �������� ++
{
    // ����������� �������� ������ �� 1
    kop++;
    // ���� ������ �������� 100, ����������� ����� �� 1 � �������� �������
    if (kop == 100)
    {
        rub++;
        kop = 0;
    }
    return *this;
}

Money Money::operator++(int) // ����������� ����� �������� ++
{
    Money temp(*this); // ������� ����� �������� �������
    // ����������� �������� ������ �� 1
    kop++;
    // ���� ������ �������� 100, ����������� ����� �� 1 � �������� �������
    if (kop == 100)
    {
        rub++;
        kop = 0;
    }
    return temp; // ���������� ����� �������� �� ����������
}
