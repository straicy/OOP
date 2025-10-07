#ifndef D1_H
#define D1_H
#include "B1.h"

class D1 : public B1 {
protected:
    int c;
public:
    D1(int x = 0, int y = 0);
    void show_D1();
};

#endif
#pragma once
