#include "List.h"
#include "error.h"

List::List()
{

}

List::List(int s, int k)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
}

// ����������� �����������
List::List(const List& a)
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

// ����������
List::~List()
{
    delete[] data;
    data = nullptr;
}

// �������� ������������
List& List::operator=(const List& a)
{
    if (this == &a)
        return *this;

    size = a.size;
    if (data != nullptr)
        delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];

    return *this;
}

// �������� ������� �� �������
int& List::operator[](int index)
{
    if (index < 0)
        throw error("index < 0"); // ���� ������ �������������, ������������ ����������

    if (index >= size)
        throw error("index ������ ������� ������"); // ���� ������ ������ ������� ������, ������������ ����������

    return data[index];
}

// �������� ��� ��������� ����� ������
int List::operator ()()
{
    return size;
}

// �������� �����-������
ostream& operator<<(ostream& out, const List& a)
{
    if (a.size == 0)
        out << "������\n";

    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";

    return out;
}

istream& operator>>(istream& in, List& a)
{
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];

    return in;
}
// �������� �������� ����� � �������� � ������� n
List List::operator-(int n)
{
    if (n < 0 || n >= size)
        throw error("������������ ������ ��� �������� - n"); // ���� ������ ������������, ������������ ����������

    List result(size - n); // ������� ����� ������ � ����������� ��������

    for (int i = 0; i < size - n; ++i)
        result[i] = data[i + n];

    return result;
}
// �������� �������� ��������� �������
List List::operator+(const List& other)
{
    if (size != other.size)
        throw error("������������� ������� ������� ��� �������� +"); // ���� ������� ������� �� ���������, ������������ ����������

    List result(size); // ������� ����� ������ � ��� �� ��������

    for (int i = 0; i < size; ++i)
        result[i] = data[i] + other.data[i];

    return result;
}
