#include "List.h"
#include "Money.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	Money t;
	List<Money>A(4, t);
	cin >> A;
	cout << A << endl;
	Money m;
	cout << "������ �� ������� 1: " << A[1];
	cout << "\n������ ������� = " << A() << endl;
	List<Money>B(4, m);
	cin >> B;
	Money C;
	cout << "�������� � �������� �� ������� A[1]+B[2]:\n";
	C = A[1] + B[2];
	cout << C;
}