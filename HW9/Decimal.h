//
// Created by IrinaT on 5/3/2019.
//

#ifndef HW9_CPP_DECIMAL_H
#define HW9_CPP_DECIMAL_H

#include <iostream>

long long gcd(long long a, long long b);

long long lcm(long long a, long long b);

class Decimal
{
public:
    Decimal(long long n, long long d);
    Decimal();

    double toDouble() const;
    void reduce();

    long long getNumerator() const;
    long long getDenominator() const;

    explicit operator bool() const;
    explicit operator long long() const;

    Decimal& operator=(Decimal const& dec);

    Decimal& operator+=(Decimal const& dec);
    Decimal& operator-=(Decimal const& dec);
    Decimal& operator*=(Decimal const& dec);
    Decimal& operator/=(Decimal const& dec);

    //trash start
    Decimal& operator&=(Decimal const& dec);
    Decimal& operator|=(Decimal const& dec);
    Decimal& operator<<=(Decimal const& dec);
    Decimal& operator>>=(Decimal const& dec);
    Decimal& operator^=(Decimal const& dec);
    //trash end

    Decimal& operator++();
    const Decimal operator++(int);
    Decimal& operator--();
    const Decimal operator--(int);

    //trash start
    Decimal& operator*();
    Decimal* operator&();
    Decimal* operator->();
    Decimal& operator->*(long long num);

    long long& operator[](int ind);
    long long const& operator[](int ind) const;

    Decimal operator,(Decimal dec);

    bool operator&(Decimal const& dec);
    bool operator|(Decimal const& dec);
    bool operator&&(Decimal const& dec);
    bool operator||(Decimal const& dec);
    //trash end

    Decimal operator+(Decimal const& dec);
    Decimal operator-(Decimal const& dec);
    Decimal operator*(Decimal const& dec);
    Decimal operator/(Decimal const& dec);

    Decimal operator<<(Decimal const& dec);
    Decimal operator>>(Decimal const& dec);

    bool operator==(Decimal const& dec);
    bool operator!=(Decimal const& dec);
    bool operator<(Decimal const& dec);
    bool operator>(Decimal const& dec);
    bool operator<=(Decimal const& dec);
    bool operator>=(Decimal const& dec);

    friend std::ostream& operator<<(std::ostream& out, Decimal const& dec);
    friend std::istream& operator>>(std::istream& in, Decimal& dec);

private:
    long long mNumerator;
    long long mDenominator;

    void swap(Decimal& dec);
    void applyCompare(Decimal const& dec, long long& num1, long long& num2);
};

#endif //HW9_CPP_DECIMAL_H
