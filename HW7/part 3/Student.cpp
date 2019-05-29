#include <utility>
#include "Student.h"

Student::Student(std::string n, std::string s, const Date d, bool se, int m) :
        Person(std::move(n), std::move(s), d, se), mNumber(m) {}

int Student::getStudentNumber() const {
    return mNumber;
}

void Student::setStudentNumber(int num) {
    num = num;
}

std::ostream &Student::print(std::ostream &out) const {
    return out << getName() << " " << getSurname() << ": " << (getSex() ? "male" : "female")
               << ", born on " << getBirthDate() << ", student number: " << getStudentNumber();
}