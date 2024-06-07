#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)return -1;//ошибка открытия файла
	int n;
	Money p;
	cout << "Количество записей: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}
int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
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
	fstream temp("temp", ios::out); // открыть для записи
	fstream stream(f_name, ios::in); // открыть для чтения
	stream.clear(); // сбросить флаги ошибок и состояния потока
	stream.seekg(0, ios::beg); // переместить указатель чтения в начало файла
	if (!stream) return -1; // ошибка открытия файла
	int i = 0;
	Money p;
	while (stream >> p) // пока есть записи в файле
	{
		if (!(p.Get_rub() > k.Get_rub() || (p.Get_rub() == k.Get_rub() && p.Get_kop() > k.Get_kop())))
		{
			temp << p; // записываем во временный файл
		}
		else
		{
			i++;
		}
	}
	// закрыть файлы
	stream.close();
	temp.close();
	remove(f_name); // удалить старый файл
	rename("temp", f_name); // переименовать временный файл
	return i; // количество удаленных записей
}
int change_file(const char* f_name, Money m)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream) return -1;//ошибка открытия файла
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p.Get_rub() == m.Get_rub() && p.Get_kop() == m.Get_kop()) // если запись равна заданному значению
		{
			p = p * 0.5; // уменьшаем запись в два раза
			temp << p; // записываем во временный файл
			l++; // увеличиваем счетчик измененных элементов
		}
		else
		{
			temp << p; // записываем во временный файл без изменений
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество измененных элементов
}
int add_file(const char* f_name, int k, Money mm) {
	fstream temp("temp", ios::out); // открыть временный файл для записи
	fstream stream(f_name, ios::in); // открыть исходный файл для чтения
	if (!stream) return -1; // ошибка открытия файла
	Money m;
	int i = 0, l = 0;
	while (stream >> m) {
		temp << m; // записать текущую запись во временный файл
		if (i == k) {
			temp << mm; // записать новую запись после элемента с заданным номером
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
