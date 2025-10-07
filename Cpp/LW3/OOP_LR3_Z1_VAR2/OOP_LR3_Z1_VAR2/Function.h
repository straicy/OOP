#pragma once
#include <iostream>
using namespace std;

class Function {
protected:
    Function* next;            // покажчик на наступний елемент списку
    static Function* head;     // статичний покажчик на початок списку

public:
    Function();                // конструктор (додає об'єкт у список)
    virtual ~Function();       // віртуальний деструктор
    virtual double value(double x) = 0;  // чисто віртуальний метод
    virtual void show() = 0;             // чисто віртуальний метод

    static void printList();   // статична функція для перегляду списку
};
#pragma once
