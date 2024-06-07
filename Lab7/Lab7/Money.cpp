#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money& Money::operator=(const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	Rub = t.Rub;
	Kop = t.Kop;
	return *this;
}
//перегрузка префиксной операции деления
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

	// Проверка на переполнение копеек
	if (result.Kop >= 100) {
		result.Rub += result.Kop / 100;
		result.Kop %= 100;
	}

	return result;
}


//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "Рубли: "; in >> t.Rub;
	cout << "Копейки: "; in >> t.Kop;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	if (t.Kop < 10)
	{
		return (out << t.Rub << ",0" << t.Kop << " руб");
	}
	else {
		return (out << t.Rub << "," << t.Kop << " руб");
	}
}
