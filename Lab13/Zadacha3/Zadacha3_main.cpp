#include "D:\all students workhome\Info 1-6\Lab11\Zadacha_2\Money.cpp"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int, Money> MMap;
typedef MMap::iterator it;
//������� ��� ������������ �������
MMap make_map(int n)
{
    MMap m;//������ �������
    Money a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        //������� ���� � ��������� �� � �������
        m.insert(make_pair(i, a));
    }
    return m;//���������� ������ ��� �������� ������ �������
}
//������� ��� ������ �������
void print_map(MMap m)
{
    for (int i = 0; i < m.size(); i++)
        cout << i << " - " << m[i] << " " << endl;
}
//���������� �������� ���������������
Money srednee(MMap& m)
{
    Money s = m[0];//������ ������� � ��������� �������� �����
    //������� �������
    for (int i = 1; i < m.size(); i++)
        s = s + m[i];
    int n = m.size();//���������� ��������� � �������
    return s / n;
}
void add_average(MMap& m)  // ������� ���������� ����. ����. � ������ 
{
    Money average = srednee(m);
    map<int, Money> new_m;
    for (const auto& pair : m) {
        new_m[pair.first + 1] = pair.second;
    }
    m = new_m;
    m.insert(m.begin(), {0, average});
}
void remove_element(map<int, Money>& m, int key) {  // �������� �������� �� �����
    MMap::iterator it = m.find(key);
    if (it != m.end()) {
        m.erase(it);
        cout << "������� � ������ " << key << " ������." << endl;
    }
    else {
        cout << "������� � ������ " << key << " �� ������." << endl;
    }
}
void subtract_min(MMap& m)  // ��������� �� ������� �������� ���. �������
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
    cout << "������� ���������� ���������:\t";
    cin >> n;
    map<int, Money> m = make_map(n);
    print_map(m);
    cout << "����������� �������� ��������������� � ������:\n";
    add_average(m);
    print_map(m);
    int key;
    cout << "Key?"; cin >> key;
    remove_element(m, key);
    print_map(m);
    cout << "����� ��������� ������������ �������� �� ������� ��������:" << endl;
    subtract_min(m);
    print_map(m);
    return 0;
}