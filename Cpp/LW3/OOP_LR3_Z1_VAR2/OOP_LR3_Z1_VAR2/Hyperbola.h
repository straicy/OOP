#pragma once
#include "Function.h"

class Hyperbola : public Function {
    double a;
public:
    Hyperbola(double a_);
    double value(double x) override;
    void show() override;
};
#pragma once
