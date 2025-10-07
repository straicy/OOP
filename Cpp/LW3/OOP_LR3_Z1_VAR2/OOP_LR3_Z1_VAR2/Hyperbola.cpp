#include "Hyperbola.h"
#include <iostream>
using namespace std;

Hyperbola::Hyperbola(double a_) : a(a_) {}

double Hyperbola::value(double x) {
    if (x == 0) {
        cout << "Попередження: ділення на нуль! ";
        return 0;
    }
    return a / x;
}

void Hyperbola::show() {
    cout << "Гіпербола: y = " << a << "/x" << endl;
}
