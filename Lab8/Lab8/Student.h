#pragma once
#include "Person.h" 

class Student : // ���������� ������, ������� ��������� ����� Person
    public Person // ���������� ������������ �� ������ Person
{
public:
    Student(void); // ����������� �� ���������
public:
    ~Student(void); // ����������
    void Show(); // ����� ��� ����������� ���������� � ��������
    void Input(); // ����� ��� ����� ���������� � ��������
    Student(string, int, float); // ����������� � �����������
    Student(const Student&); // ����������� �����������
    float Get_rating() { return rating; } // ����� ��� ��������� �������� ��������
    void Set_rating(float); // ����� ��� ��������� ��������
    Student& operator=(const Student&); // ���������� ��������� ������������
private:
    float rating; // �������
};

