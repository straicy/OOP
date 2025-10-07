#pragma once
#include "Function.h"

class Kub : public Function {
    double a, b, c;
public:
    Kub(double a_, double b_, double c_);
    double value(double x) override;
    void show() override;
};
#pragma once
