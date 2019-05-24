#include "functions.h"

#include <istream>

char* resize(const char* str, int size, int new_size)
{
    char* new_str = new char[new_size];
    if (size > new_size)
    {
        size = new_size;
    }
    for (auto i = 0; i < size; ++i)
    {
        new_str[i] = str[i];
    }
    delete[] str;
    return new_str;
}
