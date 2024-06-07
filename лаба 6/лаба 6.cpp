#include <iostream>
#include <vector>
using namespace std;
class List {
private:
    vector<int> data;

public:
    // Конструктор
    List(const vector<int>& vec) : data(vec) {}

    // Деструктор
    ~List() {}

    // Операция доступа по индексу
    int& operator[](size_t index) {
        return data[index];
    }

    // Определение размера списка
    size_t size() const {
        return data.size();
    }

    // Операция сложения элементов списков
    List operator+(const List& other) const {
        vector<int> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = data[i] + other.data[i];
        }
        return List(result);
    }

    // Класс-итератор
    class Iterator {
    private:
        const List& list;
        size_t currentIndex;

    public:
        Iterator(const List& lst, size_t startIndex = 0) : list(lst), currentIndex(startIndex) {}

        // Переход к элементу с номером n
        void operator-(int n) {
            if (currentIndex >= n) {
                currentIndex -= n;
            }
            else {
                currentIndex = 0;
            }
        }

        // Получение текущего элемента
        int operator*() const {
            return list.data[currentIndex];
        }

        // Переход к следующему элементу
        void operator++() {
            ++currentIndex;
        }

        // Проверка на конец списка
        bool operator!=(const Iterator& other) const {
            return currentIndex != other.currentIndex;
        }
    };

    // Итератор начала списка
    Iterator begin() const {
        return Iterator(*this);
    }

    // Итератор конца списка
    Iterator end() const {
        return Iterator(*this, data.size());
    }
};

int main() {
    vector<int> vec1 = { 1, 2, 3, 4, 5 };
    vector<int> vec2 = { 6, 7, 8, 9, 10 };

    List list1(vec1);
    List list2(vec2);

    // Сложение списков
    List result = list1 + list2;

    // Вывод результата
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Использование итератора
    List::Iterator it = result.begin();
    *it; // Получаем первый элемент
    *it + 2; // Переходим к элементу с номером 2
    cout << *it << endl; // Выводим элемент

    return 0;
}