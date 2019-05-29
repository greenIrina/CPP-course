//
// Created by IrinaT on 5/21/2019.
//

#include "Driver.h"

void Driver::test(PlaneFigure *pf) {
    std::cout << pf->getArea() << '\n';
    std::cout << pf->getPerimeter() << '\n';
}

void Driver::main() {
    PlaneFigure* pf = new Rect(2, 3);
    test(pf);
    delete pf;
}
