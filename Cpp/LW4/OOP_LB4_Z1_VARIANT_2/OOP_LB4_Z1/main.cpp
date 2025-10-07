#include <iostream>
#include "D3.h"
using namespace std;

int main() {
    D3 obj(1, 2, 3, 4, 5);

    cout << "Demonstration of multiple inheritance:" << endl; //Множинне наслідування через кілька рівнів (D3 ← D1 і D2 ← B1, B2)
    cout << "-------------------------------------" << endl;

    obj.show_D3();

    return 0;
}
