#pragma once
#include <iostream>
using namespace std;
class Money
{
	long Rub;
	int Kop;
public:
	Money() { Rub = 0; Kop = 0; };
	Money(long r, int k) { Rub = r; Kop = k; }
	Money(const Money& t) { Rub = t.Rub; Kop = t.Kop; }
	~Money() {};
	long get_Rub() { return Rub; }
	int get_Kop() { return Kop; }
	void set_Rub(long r) { Rub = r; }
	void set_Kop(int k) { Kop = k; }
	//перегруженные операции
	Money& operator=(const Money&);
	Money& operator/(int);
	Money operator+(const Money&);
	bool operator==(const Money& other)
	{
		return (Rub == other.Rub && Kop == other.Kop);
	}
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};

