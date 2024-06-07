#include <iostream>
#include <string>
using namespace std;
class Money {
private:
    long rubles;
    int kopecks;

public:
    // Конструкторы
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) { normalize(); }
    Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}

    // Деструктор
    ~Money() {}

    // Селекторы (геттеры)
    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }

    // Модификаторы (сеттеры)
    void setRubles(long r) { rubles = r; normalize(); }
    void setKopecks(int k) { kopecks = k; normalize(); }

    // Нормализация суммы
    void normalize() {
        rubles += kopecks / 100;
        kopecks %= 100;
    }

    // Перегрузка операций сравнения
    bool operator<(const Money& other) const {
        return (rubles * 100 + kopecks) < (other.rubles * 100 + other.kopecks);
    }
    bool operator>(const Money& other) const {
        return (rubles * 100 + kopecks) > (other.rubles * 100 + other.kopecks);
    }

    // Перегрузка операции добавления копеек
    Money& operator++() { // Префиксная форма
        kopecks++;
        normalize();
        return *this;
    }
    Money operator++(int) { // Постфиксная форма
        Money temp(*this);
        kopecks++;
        normalize();
        return temp;
    }

    // Перегрузка операций ввода и вывода
    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

// Реализация операций ввода и вывода
istream& operator>>(istream& in, Money& m) {
    in >> m.rubles >> m.kopecks;
    m.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << m.rubles << "," << m.kopecks;
    return out;
}
int main() {
    Money m1(90, 120);
    Money m2(87, 75);

    std::cout << "m1: " << m1 << std::endl;
    std::cout << "m2: " << m2 << std::endl;

    if (m1 > m2) {
        std::cout << "m1 is greater than m2" << std::endl;
    }
    else {
        std::cout << "m1 is not greater than m2" << std::endl;
    }

    ++m1;
    cout << "After ++m1: " << m1 << std::endl;

    m1++;
    cout << "After m1++: " << m1 << std::endl;

    return 0;
}