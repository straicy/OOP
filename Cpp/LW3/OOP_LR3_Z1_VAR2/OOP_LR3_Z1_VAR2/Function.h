#pragma once
#include <iostream>
using namespace std;

class Function {
protected:
    Function* next;            // �������� �� ��������� ������� ������
    static Function* head;     // ��������� �������� �� ������� ������

public:
    Function();                // ����������� (���� ��'��� � ������)
    virtual ~Function();       // ���������� ����������
    virtual double value(double x) = 0;  // ����� ���������� �����
    virtual void show() = 0;             // ����� ���������� �����

    static void printList();   // �������� ������� ��� ��������� ������
};
#pragma once
