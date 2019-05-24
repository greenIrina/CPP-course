#include <iostream>

#ifndef HW6_CPP_STRING_H
#define HW6_CPP_STRING_H

size_t strLen(const char* a);

class String
{
public:
    explicit String(const char* s);
    String(char c, size_t n);
    String(const String& s);

    ~String();

    void append(const String& ap);
    size_t size() const;
    String substring(size_t l, size_t r) const;

    int toInt() const;

    String& operator=(const String& s);
    char& operator[](size_t ind);
    char const& operator[](size_t ind) const;
    friend std::ostream& operator<<(std::ostream& out, const String& s);

private:
    size_t mSize;
    char* mStr;

    void swap(String& s);

};

String toStr(int x);

#endif //HW6_CPP_STRING_H
