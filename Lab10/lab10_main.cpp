#include "Money.h"
#include <iostream>
#include <fstream>
#include "file_work.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	Money m, m1, m2;
	int k, c;
	char file_name[30];
	do
	{ //Меню
		cout << "\n1. Создать файл";
		cout << "\n2. Вывод файла";
		cout << "\n3. Удалить все записи большие заданного значения";
		cout << "\n4. Добавить K записей после элемента с заданным номером";
		cout << "\n5. Уменьшить записи в 2 раза";
		cout << "\n0. Выход\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Имя файла?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Невозможно создать файл";
			break;
		case 2: cout << "Имя файла?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Файл пустой\n";
			if (k < 0)cout << "Невозможно открыть файл\n";
			break;
		case 3: cout << "Имя файла?"; cin >> file_name;
			cout << "Запись для удаления: "; cin >> m;
			k = del_file(file_name, m);
			if (k < 0)cout << "Невозможно открыть файл";
			break;
		case 4:
			cout << "Имя файла? ";
			cin >> file_name;
			int position;
			cout << "Введите номер элемента, после которого нужно добавить записи: ";
			cin >> position;
			int n;
			cout << "Сколько записей добавить? ";
			cin >> n;
			for (int i = 0; i < n; ++i) {
				cout << "Введите новую сумму: ";
				cin >> m1;
				k = add_file(file_name, position + i, m1); // Увеличиваем позицию для каждой новой записи
				if (k < 0) {
					cout << "Ошибка при добавлении записи" << endl;
					break; // Выходим из цикла, если произошла ошибка
				}
			}
			if (k >= 0)
				cout << "Записи успешно добавлены" << endl;
			break;
		case 5: cout << "Имя файла?";
			cin >> file_name;
			cout << "Введите сумму для уменьшения в 2 раза:\n"; cin >> m2;
			k = change_file(file_name, m2);
			if (k < 0) cout << "\nНевозможно открыть файл";
			if (k == 0) cout << "\nНет записей";
			break;
		}
	} while (c != 0);
}
