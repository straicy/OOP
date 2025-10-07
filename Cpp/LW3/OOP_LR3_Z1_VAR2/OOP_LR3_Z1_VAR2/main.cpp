#include "Function.h"
#include "Line.h"
#include "Kub.h"
#include "Hyperbola.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int n;
    cout << "Введіть кількість функцій: ";
    cin >> n;

    vector<Function*> funcs;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\nОберіть тип функції (1 - Лінійна, 2 - Квадратична, 3 - Гіпербола): ";
        cin >> type;

        if (type == 1) {
            double a, b;
            cout << "Введіть коефіцієнти a, b: ";
            cin >> a >> b;
            funcs.push_back(new Line(a, b));
        }
        else if (type == 2) {
            double a, b, c;
            cout << "Введіть коефіцієнти a, b, c: ";
            cin >> a >> b >> c;
            funcs.push_back(new Kub(a, b, c));
        }
        else if (type == 3) {
            double a;
            cout << "Введіть коефіцієнт a: ";
            cin >> a;
            funcs.push_back(new Hyperbola(a));
        }
        else {
            cout << "Невідомий тип!\n";
            i--;
        }
    }

    double x;
    cout << "\nВведіть x для обчислення функцій: ";
    cin >> x;

    cout << "\n=== Результати ===\n";
    for (size_t i = 0; i < funcs.size(); i++) {
        funcs[i]->show();
        cout << "f(" << x << ") = " << funcs[i]->value(x) << "\n";
    }

    Function::printList(); // показує всі функції зі списку

    // Звільнення пам'яті
    for (size_t i = 0; i < funcs.size(); i++) {
        delete funcs[i];
    }

    cout << "\nПрограма завершена.\n";
    return 0;
}
