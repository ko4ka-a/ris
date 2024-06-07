#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
	Vector();
	Vector(int);//конструктор с параметрами
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	int operator()();//размер вектора
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};
