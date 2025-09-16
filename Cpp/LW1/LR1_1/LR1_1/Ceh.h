#pragma once
#include <iostream>

class Ceh { 
private: 
    const char* name; // ������ �������� ��������
public:
    Ceh() : name(nullptr) {}                       // ����������� ��� ���������
    Ceh(const char* n) : name(n) {}               // ����������� � ����������

    const char* getName() const { return name; }  // �����
    void setName(const char* n) { name = n; }     // �����
};
