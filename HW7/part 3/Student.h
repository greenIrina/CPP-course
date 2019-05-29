//
// Created by IrinaT on 5/2/2019.
//

#ifndef HW7_CPP_3_STUDENT_H
#define HW7_CPP_3_STUDENT_H

#include "Person.h"


class Student : public Person {
public:
    Student(std::string n, std::string s, Date d, bool se, int m);

    int getStudentNumber() const;

    void setStudentNumber(int num);

    std::ostream &print(std::ostream &out) const override;

private:
    int mNumber;
};


#endif //HW7_CPP_3_STUDENT_H
