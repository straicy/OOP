#include "Ceh.h"        
#include <locale>
#include <iostream>

using namespace std;     

int main() {
    setlocale(LC_ALL, "ukr");
    const char* mech = "Механічний цех"; 
    const char* liva = "Ливарний цех";

    Ceh c1;             // конструктор без параметрів
    c1.setName(mech);   // присвоюємо вказівник на рядок

    Ceh c2(liva);       // конструктор з параметром

    cout << "c1: " << c1.getName() << endl;
    cout << "c2: " << c2.getName() << endl;

    // Присвоєння через сетер
    c1.setName(c2.getName());

    cout << "Після присвоювання:" << endl;
    cout << "c1: " << c1.getName() << endl;
    cout << "c2: " << c2.getName() << endl;

    return 0;
}
