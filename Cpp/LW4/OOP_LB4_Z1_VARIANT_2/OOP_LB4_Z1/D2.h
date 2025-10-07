#ifndef D2_H
#define D2_H
#include "B1.h"
#include "B2.h"

class D2 : public B1, public B2 {
protected:
    int d;
public:
    D2(int x = 0, int y = 0, int z = 0);
    void show_D2();
};

#endif
#pragma once
