#pragma once
#include "Person.h" 

class Student : // Объявление класса, который наследует класс Person
    public Person // Объявление наследования от класса Person
{
public:
    Student(void); // Конструктор по умолчанию
public:
    ~Student(void); // Деструктор
    void Show(); // Метод для отображения информации о студенте
    void Input(); // Метод для ввода информации о студенте
    Student(string, int, float); // Конструктор с параметрами
    Student(const Student&); // Конструктор копирования
    float Get_rating() { return rating; } // Метод для получения рейтинга студента
    void Set_rating(float); // Метод для установки рейтинга
    Student& operator=(const Student&); // Перегрузка оператора присваивания
private:
    float rating; // рейтинг
};

