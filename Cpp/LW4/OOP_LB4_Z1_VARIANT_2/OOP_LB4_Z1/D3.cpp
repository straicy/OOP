#include "D3.h"
#include <iostream>
using namespace std;

D3::D3(int x, int y, int z, int i, int j)
    : D1(x, y), D2(x, z, i) {
    e = j;
}

void D3::show_D3() {
    cout << "class D3:" << endl;
    D1::show_D1();
    D2::show_D2();
    cout << "e = " << e << endl;
}
