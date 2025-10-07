#ifndef D3_H
#define D3_H
#include "D1.h"
#include "D2.h"

class D3 : public D1, public D2 {
protected:
    int e;
public:
    D3(int x = 0, int y = 0, int z = 0, int i = 0, int j = 0);
    void show_D3();
};

#endif
#pragma once
