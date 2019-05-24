#include <iostream>
#include "String.h"

size_t strLen(const char* a)
{
    size_t i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    return i;
}

size_t String::size() const
{
    return mSize;
}

void String::append(const String& ap)
{
    char* new_str = new char[mSize + 1 + ap.mSize];
    for (int i = 0; i < mSize; ++i)
    {
        new_str[i] = mStr[i];
    }
    for (int i = 0; i < ap.mSize; ++i)
    {
        new_str[mSize + i] = ap.mStr[i];
    }
    delete[] mStr;
    new_str[mSize + ap.mSize] = '\0';
    mStr = new_str;
    mSize += ap.mSize;
}

String String::substring(size_t l, size_t r) const
{    //[l; r)
    size_t len = r - l;
    char* a = new char[len + 1];
    for (int i = 0; i < len; ++i)
    {
        a[i] = mStr[l + i];
    }
    a[len] = '\0';
    String res = String(a);
    delete[] a;
    return res;
}

int String::toInt() const
{
    int ans = 0;
    int st = 0;
    if (mStr[0] == '-')
    {
        st = 1;
    }
    for (int i = st; i < mSize; ++i)
    {
        int deg = 1;
        for (int j = 1; j < (mSize - i); ++j)
        {
            deg *= 10;
        }
        ans += (mStr[i] - 48) * deg;
    }
    return (mStr[0] == '-') ? -ans : ans;
}

String::String(const char* s) : mSize(strLen(s)), mStr()
{
    mStr = new char[mSize + 1];
    for (int i = 0; i < mSize; ++i)
    {
        mStr[i] = s[i];
    }
    mStr[mSize] = '\0';
}

String::String(char c, size_t n) : mSize(n), mStr()
{
    mStr = new char[n + 1];
    for (int i = 0; i < n; ++i)
    {
        mStr[i] = c;
    }
    mStr[n] = '\0';
}

String::String(String const& s) : mSize(s.mSize), mStr()
{
    mStr = new char[mSize + 1];
    for (int i = 0; i < mSize; ++i)
    {
        mStr[i] = s.mStr[i];
    }
    mStr[mSize] = '\0';
}

String::~String()
{
    delete[] mStr;
}

String& String::operator=(String const& s)
{
    String st(s);
    swap(st);
    return *this;
}

char& String::operator[](size_t ind)
{
    return *(mStr + ind);
}

char const& String::operator[](size_t ind) const
{
    return *(mStr + ind);
};

std::ostream& operator<<(std::ostream& out, const String& s)
{
    return out << s.mStr;
}

String toStr(int x)
{
    int len = 1, newSize = 1;
    int st = 0;
    if (x < 0)
    {
        st = 1;
        x = -x;
        newSize++;
    }

    while (x / len > 9)
    {
        len *= 10;
        newSize++;
    }

    char* p = new char[newSize + 1];
    if (st == 1)
    {
        p[0] = '-';
    }

    for (int i = st; i < newSize; ++i)
    {
        int deg = 1;
        for (int j = 1; j < (newSize - i); ++j)
        {
            deg *= 10;
        }
        p[i] = static_cast<char>(x / deg + 48);
        x %= deg;
    }
    p[newSize] = '\0';
    String ans(p);
    delete[] p;
    return ans;
}

void String::swap(String& s)
{
    std::swap(mSize, s.mSize);
    std::swap(mStr, s.mStr);
}
