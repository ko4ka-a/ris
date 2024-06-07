#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int n;
	Money p;
	cout << "���������� �������: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}
int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Money p; int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
int del_file(const char* f_name, Money k)
{
	fstream temp("temp", ios::out); // ������� ��� ������
	fstream stream(f_name, ios::in); // ������� ��� ������
	stream.clear(); // �������� ����� ������ � ��������� ������
	stream.seekg(0, ios::beg); // ����������� ��������� ������ � ������ �����
	if (!stream) return -1; // ������ �������� �����
	int i = 0;
	Money p;
	while (stream >> p) // ���� ���� ������ � �����
	{
		if (!(p.Get_rub() > k.Get_rub() || (p.Get_rub() == k.Get_rub() && p.Get_kop() > k.Get_kop())))
		{
			temp << p; // ���������� �� ��������� ����
		}
		else
		{
			i++;
		}
	}
	// ������� �����
	stream.close();
	temp.close();
	remove(f_name); // ������� ������ ����
	rename("temp", f_name); // ������������� ��������� ����
	return i; // ���������� ��������� �������
}
int change_file(const char* f_name, Money m)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream) return -1;//������ �������� �����
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p.Get_rub() == m.Get_rub() && p.Get_kop() == m.Get_kop()) // ���� ������ ����� ��������� ��������
		{
			p = p * 0.5; // ��������� ������ � ��� ����
			temp << p; // ���������� �� ��������� ����
			l++; // ����������� ������� ���������� ���������
		}
		else
		{
			temp << p; // ���������� �� ��������� ���� ��� ���������
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� ���������� ���������
}
int add_file(const char* f_name, int k, Money mm) {
	fstream temp("temp", ios::out); // ������� ��������� ���� ��� ������
	fstream stream(f_name, ios::in); // ������� �������� ���� ��� ������
	if (!stream) return -1; // ������ �������� �����
	Money m;
	int i = 0, l = 0;
	while (stream >> m) {
		temp << m; // �������� ������� ������ �� ��������� ����
		if (i == k) {
			temp << mm; // �������� ����� ������ ����� �������� � �������� �������
			l++;
		}
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
