//
// Created by IrinaT on 4/30/2019.
//
#include <iostream>

#ifndef HW7_CPP_PLANEFIGURE_H
#define HW7_CPP_PLANEFIGURE_H

class PlaneFigure {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual ~PlaneFigure();
};

#endif //HW7_CPP_PLANEFIGURE_H
