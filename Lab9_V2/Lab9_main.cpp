#include "List.h"
#include <iostream>
#include "error.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        // Создаем список размера 5 
        List a(5);
        cout << "Введите значения: " << endl;
        cin >> a;
        // Выводим список и его размер
        cout << "Список a: " << a << endl;
        cout << "Размер списка a: " << a() << endl;
        // Создаем еще один список такого же размера
        List b(5);
        cout << "Введите значения: " << endl;
        cin >> b;
        // Выводим список и его размер
        cout << "Список b: " << b << endl;
        cout << "Размер списка b: " << b() << endl;
        // Сложение списков a и b
        List c = a + b;
        cout << "Список c (результат сложения a и b): " << c << endl;
        cout << "Введите n: " << endl;
        int n; cin >> n;
        // Переход влево 
        List d = c - n;
        cout << "Список d (результат операции - n): " << d << endl;
        cout << "Введите индекс: " << endl;
        int index; cin >> index;
        // Доступ к элементу по индексу
        cout << "Элемент списка d с индексом : " << d[index] << endl;
    }
    catch (error e)
    {
     e.what(); // Выводим сообщение об ошибке, если оно произошло
    }
    return 0;
}
