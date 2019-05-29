//
// Created by IrinaT on 4/30/2019.
//
#include "PlaneFigure.h"

#ifndef HW7_CPP_RECT_H
#define HW7_CPP_RECT_H


class Rect : public PlaneFigure {
public:
    Rect(double w, double h);

    double getArea() override;
    double getPerimeter() override;
private:
    double width;
    double height;
};


#endif //HW7_CPP_RECT_H
