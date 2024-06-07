#include "D:\all students workhome\Info 1-6\Lab11\Zadacha_2\Money.cpp"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int, Money> MMap;
typedef MMap::iterator it;
//функция для формирования словаря
MMap make_map(int n)
{
    MMap m;//пустой словарь
    Money a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        //создаем пару и добавляем ее в словарь
        m.insert(make_pair(i, a));
    }
    return m;//возвращаем вектор как результа работы функции
}
//функция для печати словаря
void print_map(MMap m)
{
    for (int i = 0; i < m.size(); i++)
        cout << i << " - " << m[i] << " " << endl;
}
//вычисление среднего арифметического
Money srednee(MMap& m)
{
    Money s = m[0];//первый элемент – начальное значение суммы
    //перебор словаря
    for (int i = 1; i < m.size(); i++)
        s = s + m[i];
    int n = m.size();//количество элементов в словаре
    return s / n;
}
void add_average(MMap& m)  // функция добавления сред. ариф. в начало 
{
    Money average = srednee(m);
    map<int, Money> new_m;
    for (const auto& pair : m) {
        new_m[pair.first + 1] = pair.second;
    }
    m = new_m;
    m.insert(m.begin(), {0, average});
}
void remove_element(map<int, Money>& m, int key) {  // удаление элемента по ключу
    MMap::iterator it = m.find(key);
    if (it != m.end()) {
        m.erase(it);
        cout << "Элемент с ключом " << key << " удален." << endl;
    }
    else {
        cout << "Элемент с ключом " << key << " не найден." << endl;
    }
}
void subtract_min(MMap& m)  // вычитание из каждого элемента мин. элемент
{
    Money minElem = m.begin()->second;
    for (auto& pair : m)
    {
        if (pair.second < minElem)
        {
            minElem = pair.second;
        }
    }
    for (auto& pair : m) {
        pair.second = pair.second - minElem;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите количество элементов:\t";
    cin >> n;
    map<int, Money> m = make_map(n);
    print_map(m);
    cout << "Добавленние среднего арифметического в начало:\n";
    add_average(m);
    print_map(m);
    int key;
    cout << "Key?"; cin >> key;
    remove_element(m, key);
    print_map(m);
    cout << "После вычитания минимального элемента из каждого элемента:" << endl;
    subtract_min(m);
    print_map(m);
    return 0;
}