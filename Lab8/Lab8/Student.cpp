#include "Student.h"
#include <iostream>
Student::Student(void) :Person()
{
	rating = 0;
}
Student::~Student(void)
{}
Student::Student(string N, int A, float R) :Person(N, A)
{
	rating = R;
}
Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	rating = S.rating;
}
void Student::Set_rating(float R)
{
	rating = R;
}

Student& Student::operator=(const Student& S)
{
	if (&S == this)return *this;
	name = S.name;
	age = S.age;
	rating = S.rating;
	return *this;
}
void Student::Show()
{
	cout << "\nИмя : " << name;
	cout << "\nВозраст : " << age;
	cout << "\nРейтинг : " << rating;
	cout << "\n";
}
void Student::Input()
{
	cout << "\nИмя:"; cin >> name;
	cout << "\nВозраст:"; cin >> age;
	cout << "\nРейтинг:"; cin >> rating;
}