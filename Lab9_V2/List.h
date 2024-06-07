#pragma once
#include <iostream>
using namespace std;

class List
{
public:
    List(); // ����������� �� ���������
    List(int n, int value = 0); // ����������� � �����������: �������� ������ ��� n ���������
    List(const List& s); // ����������� �����������
    ~List(); // ����������
    List& operator=(const List& s); // �������� ������������
    int& operator[](int index); // �������� ������� �� �������
    int operator()(); // �������� ����������� ������� ������
    List operator-(int);
    List operator+(const List&);
    // ������������� �������� �����-������
    friend ostream& operator<<(ostream& out, const List& a); // ������������� ������� ������
    friend istream& operator>>(istream& in, List& a); // ������������� ������� �����

private:
    int size; // ������ ������
    int* data; // ��������� �� ������������ ������ ��������
};