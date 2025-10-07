#include "D1.h"
#include <iostream>
using namespace std;

D1::D1(int x, int y) : B1(x) {
    c = y;
}

void D1::show_D1() {
    cout << "class D1:" << endl;
    show_B1();
    cout << "c = " << c << endl;
}
