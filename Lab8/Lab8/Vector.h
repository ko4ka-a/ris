#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
	Vector();
	Vector(int);//����������� � �����������
	~Vector(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	int operator()();//������ �������
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};
