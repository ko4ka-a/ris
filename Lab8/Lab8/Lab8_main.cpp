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
    SetConsoleCP(1251);  // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    Dialog D;
    D.Execute();
    return 0;
}