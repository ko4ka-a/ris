#include <iostream>
using namespace std;
class TRAID {
private:
    int first;
    int second;
    int third;

public:
    TRAID() {
        first = 0;
        second = 0;
        third = 0;
    }

    TRAID(int first, int second, int third) {
        this->first = first;
        this->second = second;
        this->third = third;
    }

    ~TRAID() {
        // деструктор
    }

    void setFirst(int value) {
        first = value;
    }

    void setSecond(int value) {
        second = value;
    }

    void setThird(int value) {
        third = value;
    }

    void incrementFields() {
        first++;
        second++;
        third++;
    }

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }

    int getThird() const {
        return third;
    }

    TRAID& operator=(const TRAID& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
            third = other.third;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const TRAID& obj) {
        os << "First: " << obj.first << ", Second: " << obj.second << ", Third: " << obj.third;
        return os;
    }

    friend istream& operator>>(istream& is, TRAID& obj) {
        is >> obj.first >> obj.second >> obj.third;
        return is;
    }
};

class DerivedTRAID : public TRAID {
public:
    DerivedTRAID() : TRAID() {
        // конструктор производного класса
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    TRAID obj1;
    cout << "Object 1: " << obj1 << endl;

    TRAID obj2(1, 2, 3);
    cout << "Object 2: " << obj2 << endl;

    TRAID obj3;
    cout << "Enter values for Object 3 (first, second, third): ";
    cin >> obj3;
    cout << "Object 3: " << obj3 << endl;

    obj3.incrementFields();
    cout << "Object 3 after increment: " << obj3 << endl;

    DerivedTRAID derivedObj;
    derivedObj.setFirst(4);
    cout << "Derived Object: " << derivedObj << endl;

    return 0;
}