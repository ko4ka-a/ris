#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include "Object.h"
#include "Dialog.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);  // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    Dialog D;
    D.Execute();
    return 0;
}