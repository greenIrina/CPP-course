//
// Created by IrinaT on 5/2/2019.
//

#ifndef HW7_CPP_3_DATE_H
#define HW7_CPP_3_DATE_H

#include <iostream>
#include <string>

class Date {
public:
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

private:
    int mDay;
    int mMonth;
    int mYear;

};

std::ostream &operator<<(std::ostream &out, const Date &d);

#endif //HW7_CPP_3_DATE_H
