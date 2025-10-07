#include "Kub.h"
#include <iostream>
using namespace std;

Kub::Kub(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

double Kub::value(double x) {
    return a * x * x + b * x + c;
}

void Kub::show() {
    cout << "Квадратична функція: y = " << a << "*x^2 + " << b << "*x + " << c << endl;
}
