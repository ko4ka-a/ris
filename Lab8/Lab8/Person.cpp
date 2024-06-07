#include "Person.h"
#include <iostream>
#include "Event.h"
Person::Person(void) {
	name = "";
	age = 0;
}
//деструктор
Person::~Person(void) {}
//констрктор с параметрами
Person::Person(string Name, int Age)
{
	name = Name;
	age = Age;
}
//конструктор копирования
Person::Person(const Person& pers)
{
	name = pers.name;
	age = pers.age;
}
//селекторы
void Person::Set_name(string N)
{
	name = N;
}
void Person::Set_age(int A)
{
	age = A;
}
//оператор присваивания
Person& Person::operator=(const Person& p)
{
	if (&p == this)return *this;
	name = p.name;
	age = p.age;
	return *this;
}
//метод для просмотра атрибутов
void Person::Show()
{
	cout << "\nИмя : " << name;
	cout << "\nВозраст : " << age;
	cout << "\n";
}
//метод для ввода значений атрибутов
void Person::Input()
{
	cout << "\nИмя:"; cin >> name;
	cout << "\nВозраст:"; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet: Show();  // вывод информации об объекте
			break;
		}
	}
}