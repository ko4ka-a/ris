#include "Person.h"
#include <iostream>
#include "Event.h"
Person::Person(void) {
	name = "";
	age = 0;
}
//����������
Person::~Person(void) {}
//���������� � �����������
Person::Person(string Name, int Age)
{
	name = Name;
	age = Age;
}
//����������� �����������
Person::Person(const Person& pers)
{
	name = pers.name;
	age = pers.age;
}
//���������
void Person::Set_name(string N)
{
	name = N;
}
void Person::Set_age(int A)
{
	age = A;
}
//�������� ������������
Person& Person::operator=(const Person& p)
{
	if (&p == this)return *this;
	name = p.name;
	age = p.age;
	return *this;
}
//����� ��� ��������� ���������
void Person::Show()
{
	cout << "\n��� : " << name;
	cout << "\n������� : " << age;
	cout << "\n";
}
//����� ��� ����� �������� ���������
void Person::Input()
{
	cout << "\n���:"; cin >> name;
	cout << "\n�������:"; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//�������-���������
	{
		switch (e.command)
		{
		case cmGet: Show();  // ����� ���������� �� �������
			break;
		}
	}
}