#include "C:\Users\User\Desktop\���� �� ���� 2 �������\���\11 variant\Lab13\Zadacha2/x64"
#include "vector"
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<Money> MVector;
Money s;
struct Comp_less // ��� ���������� �� ��������
{
public:
	bool operator()(Money m1, Money m2)
	{
		if (m1 > m2) return true;
		else return false;
	}
};
//������������ �������
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
// ���������� �������� ��������������� � ���������� � ������ ����������
void add_average_to_beginning(MVector& v) {
	if (v.empty()) {
		cout << "������ ����." << endl;
		return;
	}
	Money sum ;
	for (const Money& m : v) {
		sum = sum + m;
	}
	Money average(sum / v.size());
	v.insert(v.begin(), average);
}
//������ �������
void print_vector(MVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}
// �� ������� �������� �������� ����������� ������� ����������
void subtractMin(MVector& v) {
	if (v.empty()) {
		cout << "������ ����." << endl;
		return;
	}

	// ������� ����������� �������
	Money minElement = *min_element(v.begin(), v.end());

	// �������� ����������� ������� �� ������� ��������
	for (Money& m : v) {
		m = m - minElement;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "������� ���������� ���������:\t";
	cin >> n;
	MVector v;
	v = make_vector(n);
	print_vector(v);
	add_average_to_beginning(v);
	cout << "����������� �������� ��������������� � ������:\n";
	print_vector(v);
	//�� ��������
	cout << "���������� �� ��������:" << endl;
	sort(v.begin(), v.end(), Comp_less());
	print_vector(v);
	//�� �����������
	cout << "���������� �� �����������:" << endl;
	sort(v.begin(), v.end());
	print_vector(v);
	// ����� ������� � �������� ������ � ������� ��� �� ����������
	Money key;
	cout << "Key\t?";
	cin >> key;
	auto it = find(v.begin(), v.end(), key);
	if (it != v.end()) {
		cout << "������� ������ � �������: " << distance(v.begin(), it) << endl;
	}
	else {
		cout << "������� �� ������." << endl;
	}
	cout << "�������� �������� � �������� ������:" << endl;
	v.erase(remove(v.begin(), v.end(), key), v.end());
	print_vector(v);
	cout << "����� ��������� ������������ �������� �� ������� ��������:" << endl;
	subtractMin(v);
	print_vector(v);
}