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
//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "Рубли: "; in >> t.rub;
	cout << "Копейки: "; in >> t.kop;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	if (t.kop < 10)
	{
		return (out << t.rub << ",0" << t.kop << " руб");
	}
	else {
		return (out << t.rub << "," << t.kop << " руб");
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
Money Money::operator*(const double num) //перегрузка префиксной операции умножения
{
	Money result;
	long totalKop = (rub * 100 + kop) * num;
	result.rub = totalKop / 100;
	result.kop = totalKop % 100;
	return result;
}
bool Money::operator<(const Money& other) const
{
    // Сравниваем рубли, если они равны, сравниваем копейки
    if (rub == other.rub)
    {
        return kop < other.kop;
    }
    // Если рубли разные, возвращаем результат сравнения рублей
    return rub < other.rub;
}

bool Money::operator>(const Money& other) const
{
    // Сравниваем рубли, если они равны, сравниваем копейки
    if (rub == other.rub)
    {
        return kop > other.kop;
    }
    // Если рубли разные, возвращаем результат сравнения рублей
    return rub > other.rub;
}

Money& Money::operator++() // префиксная форма операции ++
{
    // Увеличиваем значение копеек на 1
    kop++;
    // Если копеек достигло 100, увеличиваем рубли на 1 и обнуляем копейки
    if (kop == 100)
    {
        rub++;
        kop = 0;
    }
    return *this;
}

Money Money::operator++(int) // постфиксная форма операции ++
{
    Money temp(*this); // Создаем копию текущего объекта
    // Увеличиваем значение копеек на 1
    kop++;
    // Если копеек достигло 100, увеличиваем рубли на 1 и обнуляем копейки
    if (kop == 100)
    {
        rub++;
        kop = 0;
    }
    return temp; // Возвращаем копию значения до увеличения
}
