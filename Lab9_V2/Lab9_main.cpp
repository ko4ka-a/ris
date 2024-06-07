#include "List.h"
#include <iostream>
#include "error.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        // ������� ������ ������� 5 
        List a(5);
        cout << "������� ��������: " << endl;
        cin >> a;
        // ������� ������ � ��� ������
        cout << "������ a: " << a << endl;
        cout << "������ ������ a: " << a() << endl;
        // ������� ��� ���� ������ ������ �� �������
        List b(5);
        cout << "������� ��������: " << endl;
        cin >> b;
        // ������� ������ � ��� ������
        cout << "������ b: " << b << endl;
        cout << "������ ������ b: " << b() << endl;
        // �������� ������� a � b
        List c = a + b;
        cout << "������ c (��������� �������� a � b): " << c << endl;
        cout << "������� n: " << endl;
        int n; cin >> n;
        // ������� ����� 
        List d = c - n;
        cout << "������ d (��������� �������� - n): " << d << endl;
        cout << "������� ������: " << endl;
        int index; cin >> index;
        // ������ � �������� �� �������
        cout << "������� ������ d � �������� : " << d[index] << endl;
    }
    catch (error e)
    {
     e.what(); // ������� ��������� �� ������, ���� ��� ���������
    }
    return 0;
}
