#pragma once
#include <string>
#include <iostream>
using namespace std;
class Car 
{
public:
	Car(void);
public:
	Car(void);
	virtual ~Car(void);
	Car(string, int, int);
	Car(const Car&);
	string Ger_mark() { return mark; }
		int Get_cyl(){return cyl;}
		int Get_power(){return power;}
		void Set_mark(string);
		void Set_cyl(int);
		void Set_power(int);
	Car& operator= (const Car&);
	friend istream& operator>>(istream& in, Car& c);
	friend ostream& operator<<(ostream& out, const Car& c);
protected:
	string mark;
	int cyl;
	int power;
};
