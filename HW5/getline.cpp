//
// Created by IrinaT on 4/24/2019.
//
#include "functions.h"
#include <istream>

//bool k -- do we need to add more capacity for just '\0' or to
//ordinary symbols
char* apply(size_t it, size_t& size, char* str, bool k)
{
    if (it == size)
    {
        k ? (size *= 2) : (size += 1);
        char* tmp = new char[size];
        for (int i = 0; i < size; ++i)
        {
            tmp[i] = str[i];
        }
        delete[] str;
        return tmp;
    }
    return str;
}


char* getline(std::istream& stream)
{
    size_t const INITIAL_SIZE = 10;
    char* str = new char[INITIAL_SIZE];
    char ch;
    size_t it = 0, size = INITIAL_SIZE;
    while (stream.get(ch) && ch != '\n')
    {
        str = apply(it, size, str, false);
        str[it] = ch;
        it++;
    }
    if (it == size)
    {
        str = apply(it, size, str, true);
    }
    str[it] = '\0';

    return str;
}
