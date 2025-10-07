#include "Line.h"
#include <iostream>
using namespace std;

Line::Line(double a_, double b_) : a(a_), b(b_) {}

double Line::value(double x) {
    return a * x + b;
}

void Line::show() {
    cout << "Ë³í³éíà ôóíêö³ÿ: y = " << a << "*x + " << b << endl;
}
