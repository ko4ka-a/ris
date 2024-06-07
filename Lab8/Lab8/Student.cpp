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
	cout << "\n��� : " << name;
	cout << "\n������� : " << age;
	cout << "\n������� : " << rating;
	cout << "\n";
}
void Student::Input()
{
	cout << "\n���:"; cin >> name;
	cout << "\n�������:"; cin >> age;
	cout << "\n�������:"; cin >> rating;
}