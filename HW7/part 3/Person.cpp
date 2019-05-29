#include <utility>
#include "Person.h"

Person::Person(std::string n, std::string s, const Date d, bool se) : mName(std::move(n)), mSurname(std::move(s)),
                                                                      mDate(d), mSex(se) {}

std::string Person::getName() const {
    return mName;
}

std::string Person::getSurname() const {
    return mSurname;
}

Date Person::getBirthDate() const {
    return mDate;
}

bool Person::getSex() const {
    return mSex;
}

std::ostream &Person::print(std::ostream &out) const {
    return out << getName() << " " << getSurname() << ": " << (getSex() ? "male" : "female")
               << ", born on " << getBirthDate();
}

void Person::setName(std::string name) {
    this->mName = std::move(name);
}

void Person::setSurname(std::string surname) {
    this->mSurname = std::move(surname);
}

void Person::setDate(Date date) {
    this->mDate = date;
}

void Person::setSex(bool male) {
    this->mSex = male;
}

std::ostream &operator<<(std::ostream &out, const Person &p) {
    return p.print(out);
}

