//
// Created by IrinaT on 5/2/2019.
//

#include "Date.h"

Date::Date(int d, int m, int y) : mDay(d), mMonth(m), mYear(y) {}

int Date::getDay() const {
    return mDay;
}

int Date::getMonth() const {
    return mMonth;
}

int Date::getYear() const {
    return mYear;
}

void Date::setDay(int day) {
    this->mDay = day;
}

void Date::setMonth(int month) {
    this->mMonth = month;
}

void Date::setYear(int year) {
    this->mYear = year;
}

std::ostream &operator<<(std::ostream &out, const Date &d) {
    return out << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
}
