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

// Конструктор копирования
List::List(const List& a)
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

// Деструктор
List::~List()
{
    delete[] data;
    data = nullptr;
}

// Оператор присваивания
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

// Оператор доступа по индексу
int& List::operator[](int index)
{
    if (index < 0)
        throw error("index < 0"); // если индекс отрицательный, генерируется исключение

    if (index >= size)
        throw error("index больше размера списка"); // если индекс больше размера списка, генерируется исключение

    return data[index];
}

// Оператор для получения длины списка
int List::operator ()()
{
    return size;
}

// Операции ввода-вывода
ostream& operator<<(ostream& out, const List& a)
{
    if (a.size == 0)
        out << "Пустой\n";

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
// Оператор перехода влево к элементу с номером n
List List::operator-(int n)
{
    if (n < 0 || n >= size)
        throw error("недопустимый индекс для операции - n"); // если индекс недопустимый, генерируется исключение

    List result(size - n); // Создаем новый список с уменьшенным размером

    for (int i = 0; i < size - n; ++i)
        result[i] = data[i + n];

    return result;
}
// Оператор сложения элементов списков
List List::operator+(const List& other)
{
    if (size != other.size)
        throw error("несовместимые размеры списков для операции +"); // если размеры списков не совпадают, генерируется исключение

    List result(size); // Создаем новый список с тем же размером

    for (int i = 0; i < size; ++i)
        result[i] = data[i] + other.data[i];

    return result;
}
