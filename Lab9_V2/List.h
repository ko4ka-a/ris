#pragma once
#include <iostream>
using namespace std;

class List
{
public:
    List(); // Конструктор по умолчанию
    List(int n, int value = 0); // Конструктор с параметрами: выделяет память под n элементов
    List(const List& s); // Конструктор копирования
    ~List(); // Деструктор
    List& operator=(const List& s); // Оператор присваивания
    int& operator[](int index); // Оператор доступа по индексу
    int operator()(); // Оператор определения размера списка
    List operator-(int);
    List operator+(const List&);
    // Перегруженные операции ввода-вывода
    friend ostream& operator<<(ostream& out, const List& a); // Дружественная функция вывода
    friend istream& operator>>(istream& in, List& a); // Дружественная функция ввода

private:
    int size; // Размер списка
    int* data; // Указатель на динамический массив значений
};