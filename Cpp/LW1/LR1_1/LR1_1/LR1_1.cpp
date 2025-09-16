#include "Ceh.h"        
#include <locale>
#include <iostream>

using namespace std;     

int main() {
    setlocale(LC_ALL, "ukr");
    const char* mech = "��������� ���"; 
    const char* liva = "�������� ���";

    Ceh c1;             // ����������� ��� ���������
    c1.setName(mech);   // ���������� �������� �� �����

    Ceh c2(liva);       // ����������� � ����������

    cout << "c1: " << c1.getName() << endl;
    cout << "c2: " << c2.getName() << endl;

    // ��������� ����� �����
    c1.setName(c2.getName());

    cout << "ϳ��� ������������:" << endl;
    cout << "c1: " << c1.getName() << endl;
    cout << "c2: " << c2.getName() << endl;

    return 0;
}
