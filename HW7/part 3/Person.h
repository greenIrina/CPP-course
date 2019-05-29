#ifndef HW7_CPP_3_PERSON_H
#define HW7_CPP_3_PERSON_H

#include "Date.h"

class Person {
public:
    Person(std::string n, std::string s, Date d, bool se);

    std::string getName() const;
    std::string getSurname() const;
    Date getBirthDate() const;
    bool getSex() const;

    virtual std::ostream &print(std::ostream &out) const;

    void setName(std::string name);
    void setSurname(std::string surname);
    void setDate(Date date);
    void setSex(bool male);

private:
    std::string mName;
    std::string mSurname;
    Date mDate;
    bool mSex;

};
std::ostream &operator<<(std::ostream &out, const Person &p);

#endif //HW7_CPP_3_PERSON_H
