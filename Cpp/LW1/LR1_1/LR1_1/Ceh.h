#pragma once
#include <iostream>

class Ceh { 
private: 
    const char* name; // просто зберігаємо вказівник
public:
    Ceh() : name(nullptr) {}                       // конструктор без параметрів
    Ceh(const char* n) : name(n) {}               // конструктор з параметром

    const char* getName() const { return name; }  // гетер
    void setName(const char* n) { name = n; }     // сетер
};
