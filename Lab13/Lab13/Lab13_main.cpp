#include "C:\Users\User\Desktop\Лабы по инфе 2 семестр\ооп\11 variant\Lab13\Zadacha2/x64"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<Money> MVector;
Money s;
struct Comp_less // для сортировки по убыванию
{
public:
	bool operator()(Money m1, Money m2)
	{
		if (m1 > m2) return true;
		else return false;
	}
};
//формирование вектора
MVector make_vector(int n)
{
	Money a;
	MVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
// Нахождение среднего арифметического и добавление в начало контейнера
void add_average_to_beginning(MVector& v) {
	if (v.empty()) {
		cout << "Вектор пуст." << endl;
		return;
	}
	Money sum ;
	for (const Money& m : v) {
		sum = sum + m;
	}
	Money average(sum / v.size());
	v.insert(v.begin(), average);
}
//печать вектора
void print_vector(MVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}
// Из каждого элемента вычитаем минимальный элемент контейнера
void subtractMin(MVector& v) {
	if (v.empty()) {
		cout << "Вектор пуст." << endl;
		return;
	}

	// Находим минимальный элемент
	Money minElement = *min_element(v.begin(), v.end());

	// Вычитаем минимальный элемент из каждого элемента
	for (Money& m : v) {
		m = m - minElement;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество элементов:\t";
	cin >> n;
	MVector v;
	v = make_vector(n);
	print_vector(v);
	add_average_to_beginning(v);
	cout << "Добавленние среднего арифметического в начало:\n";
	print_vector(v);
	//по убыванию
	cout << "Сортировка по убыванию:" << endl;
	sort(v.begin(), v.end(), Comp_less());
	print_vector(v);
	//по возрастанию
	cout << "Сортировка по возрастанию:" << endl;
	sort(v.begin(), v.end());
	print_vector(v);
	// Найти элемент с заданным ключом и удалить его из контейнера
	Money key;
	cout << "Key\t?";
	cin >> key;
	auto it = find(v.begin(), v.end(), key);
	if (it != v.end()) {
		cout << "Элемент найден в позиции: " << distance(v.begin(), it) << endl;
	}
	else {
		cout << "Элемент не найден." << endl;
	}
	cout << "Удаление элемента с заданным ключем:" << endl;
	v.erase(remove(v.begin(), v.end(), key), v.end());
	print_vector(v);
	cout << "После вычитания минимального элемента из каждого элемента:" << endl;
	subtractMin(v);
	print_vector(v);
}