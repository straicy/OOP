#include "D2.h"
#include <iostream>
using namespace std;

D2::D2(int x, int y, int z) : B1(x), B2(y) {
    d = z;
}

void D2::show_D2() {
    cout << "class D2:" << endl;
    show_B1();
    show_B2();
    cout << "d = " << d << endl;
}
