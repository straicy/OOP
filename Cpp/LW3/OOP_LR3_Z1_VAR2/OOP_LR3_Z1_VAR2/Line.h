#pragma once
#include "Function.h"

class Line : public Function {
    double a, b;
public:
    Line(double a_, double b_);
    double value(double x) override;
    void show() override;
};
#pragma once
