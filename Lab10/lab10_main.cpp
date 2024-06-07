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
	{ //����
		cout << "\n1. ������� ����";
		cout << "\n2. ����� �����";
		cout << "\n3. ������� ��� ������ ������� ��������� ��������";
		cout << "\n4. �������� K ������� ����� �������� � �������� �������";
		cout << "\n5. ��������� ������ � 2 ����";
		cout << "\n0. �����\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "��� �����?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "���������� ������� ����";
			break;
		case 2: cout << "��� �����?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "���� ������\n";
			if (k < 0)cout << "���������� ������� ����\n";
			break;
		case 3: cout << "��� �����?"; cin >> file_name;
			cout << "������ ��� ��������: "; cin >> m;
			k = del_file(file_name, m);
			if (k < 0)cout << "���������� ������� ����";
			break;
		case 4:
			cout << "��� �����? ";
			cin >> file_name;
			int position;
			cout << "������� ����� ��������, ����� �������� ����� �������� ������: ";
			cin >> position;
			int n;
			cout << "������� ������� ��������? ";
			cin >> n;
			for (int i = 0; i < n; ++i) {
				cout << "������� ����� �����: ";
				cin >> m1;
				k = add_file(file_name, position + i, m1); // ����������� ������� ��� ������ ����� ������
				if (k < 0) {
					cout << "������ ��� ���������� ������" << endl;
					break; // ������� �� �����, ���� ��������� ������
				}
			}
			if (k >= 0)
				cout << "������ ������� ���������" << endl;
			break;
		case 5: cout << "��� �����?";
			cin >> file_name;
			cout << "������� ����� ��� ���������� � 2 ����:\n"; cin >> m2;
			k = change_file(file_name, m2);
			if (k < 0) cout << "\n���������� ������� ����";
			if (k == 0) cout << "\n��� �������";
			break;
		}
	} while (c != 0);
}
