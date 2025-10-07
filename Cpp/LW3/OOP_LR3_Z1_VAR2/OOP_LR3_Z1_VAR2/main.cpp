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
    cout << "������ ������� �������: ";
    cin >> n;

    vector<Function*> funcs;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\n������ ��� ������� (1 - ˳����, 2 - �����������, 3 - ó�������): ";
        cin >> type;

        if (type == 1) {
            double a, b;
            cout << "������ ����������� a, b: ";
            cin >> a >> b;
            funcs.push_back(new Line(a, b));
        }
        else if (type == 2) {
            double a, b, c;
            cout << "������ ����������� a, b, c: ";
            cin >> a >> b >> c;
            funcs.push_back(new Kub(a, b, c));
        }
        else if (type == 3) {
            double a;
            cout << "������ ���������� a: ";
            cin >> a;
            funcs.push_back(new Hyperbola(a));
        }
        else {
            cout << "�������� ���!\n";
            i--;
        }
    }

    double x;
    cout << "\n������ x ��� ���������� �������: ";
    cin >> x;

    cout << "\n=== ���������� ===\n";
    for (size_t i = 0; i < funcs.size(); i++) {
        funcs[i]->show();
        cout << "f(" << x << ") = " << funcs[i]->value(x) << "\n";
    }

    Function::printList(); // ������ �� ������� � ������

    // ��������� ���'��
    for (size_t i = 0; i < funcs.size(); i++) {
        delete funcs[i];
    }

    cout << "\n�������� ���������.\n";
    return 0;
}
