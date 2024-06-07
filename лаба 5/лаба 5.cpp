#include <iostream>
#include <vector>
using namespace std;
class TRIAD {
protected:
    int first;
    int second;
    int third;

public:
    TRIAD(int f = 0, int s = 0, int t = 0) : first(f), second(s), third(t) {}

    virtual void increase() {
        first++;
        second++;
        third++;
    }

    virtual void increase(int n) = 0; // Абстрактный метод

    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }
    void setThird(int t) { third = t; }

    virtual void display() const {
        cout << "(" << first << ", " << second << ", " << third << ")";
    }
};

class TIME : public TRIAD {
public:
    TIME(int h = 0, int m = 0, int s = 0) : TRIAD(h, m, s) {}

    void increase() override {
        third++;
        if (third == 60) {
            third = 0;
            second++;
            if (second == 60) {
                second = 0;
                first++;
                if (first == 24) {
                    first = 0;
                }
            }
        }
    }

    void increase(int n) override {
        for (int i = 0; i < n; i++) {
            increase();
        }
    }

    void increaseSeconds(int n) {
        third += n;
        while (third >= 60) {
            third -= 60;
            second++;
            if (second == 60) {
                second = 0;
                first++;
                if (first == 24) {
                    first = 0;
                }
            }
        }
    }

    void increaseMinutes(int n) {
        second += n;
        while (second >= 60) {
            second -= 60;
            first++;
            if (first == 24) {
                first = 0;
            }
        }
    }

    void display() const override {
        cout << "Time: " << first << ":" << second << ":" << third;
    }
};

class Vector {
private:
    vector<TRIAD*> elements;

public:
    void add(TRIAD * t) {
        elements.push_back(t);
    }

    void display() const {
        for (const auto& t : elements) {
            t->display();
            cout << endl;
        }
    }
};

int main() {
    Vector v;
    TRIAD* ptr;
    ptr = new TIME;
    TIME t1(1,2,3);
    TIME t2(12, 30, 50);

    v.add(&t1);
    v.add(&t2);
    
    t2.increase(5);

    v.display();

    return 0;
}