#include "D:\all students workhome\Info 1-6\Lab11\Zadacha_2\Money.cpp"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef queue<Money> Que;
typedef vector<Money> Vec;

Que make_queue(int n)
{
    Que q;
    Money m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        q.push(m);
    }
    return q;
}

Vec copy_queue_to_vector(Que q) // ����������� ������� � ������
{
    Vec v;
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

Que copy_vector_to_queue(Vec v)  // ����������� ������� � �������
{
    Que q;
    for (int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }
    return q;
}

void print_queue(Que q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void remove_element(queue<Money>& q, Money& key){  // �������� �������� �� �����
Vec v = copy_queue_to_vector(q);
v.erase(remove(v.begin(), v.end(), key), v.end());
q = copy_vector_to_queue(v);
}
void find_element(queue<Money> q, Money key) // ������� ������ ��������
{
    Vec v = copy_queue_to_vector(q);
    auto it = find(v.begin(), v.end(), key);
    if (it != v.end())
    {
        cout << "������� ������: " << *it << endl;
    }
    else
    {
        cout << "������� �� ������." << endl;
    }
}
void add_average_to_beginning(queue<Money>& q) {  // ���������� ����. ����. � ������ 
    if (q.empty()) {
        cout << "������� �����." << endl;
        return;
    }
    Vec v = copy_queue_to_vector(q);
    Money sum;
    for (const Money& m : v) {
        sum = sum + m;
    }
    Money average(sum / v.size());
    v.insert(v.begin(), average);
    q = copy_vector_to_queue(v);
}
void subtractMin(queue<Money>& q)
{
    if (q.empty())
    {
        cout << "������� ������" << endl;
        return;
    }
    Vec v = copy_queue_to_vector(q);
    Money minElement = *min_element(v.begin(), v.end());
    for_each(v.begin(), v.end(), [minElement](Money& m) {
        m = m - minElement;
        });
    q = copy_vector_to_queue(v);
}
struct Comp_less // ��� ���������� �� ��������
{
public:
    bool operator()(Money m1, Money m2)
    {
        if (m1 > m2) return true;
        else return false;
    }
};
void sort_less(queue<Money>& q)
{
    Vec v = copy_queue_to_vector(q);
    sort(v.begin(), v.end(), Comp_less());
    q = copy_vector_to_queue(v);
    cout << "��������� ������������ �� ��������:" << endl;
}
void sort_greater(queue<Money>& q)
{
    Vec v = copy_queue_to_vector(q);
    sort(v.begin(), v.end());
    q = copy_vector_to_queue(v);
    cout << "��������� ������������ �� �����������:" << endl;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    Money key;
    Que q;
    int n;
    cout << "n?";
    cin >> n;
    q = make_queue(n);
    print_queue(q);
    add_average_to_beginning(q);
    cout << "����������� �������� ��������������� � ������:\n";
    print_queue(q);
    // ���������� �� ��������
    sort_less(q);
    print_queue(q);
    sort_greater(q); // ���������� �� �����������
    print_queue(q);
    cout << "Key?";
    cin >> key;
    find_element(q, key);
    cout << "�������� �������� � �������� ������:" << endl;
    remove_element(q, key);
    print_queue(q);
    cout << "����� ��������� ������������ �������� �� ������� ��������:" << endl;
    subtractMin(q);
    print_queue(q);
    return 0;
}
