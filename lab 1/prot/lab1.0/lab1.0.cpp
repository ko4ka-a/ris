#include <iostream>
using namespace std;
class Pair {
private:
    double first; // оклад
    int second;   // количество отработанных дней

public:
    // Метод инициализации
    void Init(double f, int s) 
    {
        first = f;
        second = s;
    }

    // Метод ввода с клавиатуры
    void Read() 
    {
        double f;
        int s;
        cout << "Введите оклад: ";
        cin >> f;
        cout << "Введите количество отработанных дней: ";
        cin >> s;
        Init(f, s);
    }

    // Метод вывода на экран
    void Show()
    {
        cout << "Оклад: " << first << ", Количество отработанных дней: " << second << endl;
    }

    // Метод вычисления суммы
    double summa() 
    {
        const int daysInMonth = 30; // Предполагаем, что в месяце 30 дней
        return (first / daysInMonth) * second;
    }
};

// Внешняя функция создания объекта Pair
Pair make_Pair(double f, int s) {
    if (f <= 0 || s <= 0) {
        cerr << "Ошибка: некорректные параметры." << endl;
        exit(1);
    }
    Pair p;
    p.Init(f, s);
    return p;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // Создание объекта класса Pair
    Pair p1;
    p1.Read();
    p1.Show();
    cout << "Начисленная сумма: " << p1.summa() << endl;

    // Создание объекта класса Pair с помощью внешней функции
    Pair p2 = make_Pair(500.0, 20);
    p2.Show();
    cout << "Начисленная сумма: " << p2.summa() << endl;

    // Массив объектов Pair
    Pair arr[2];
    for (int i = 0; i < 2; i++) {
        arr[i].Read();
        arr[i].Show();
        cout << "Начисленная сумма: " << arr[i].summa() << endl;
    }

    return 0;
}