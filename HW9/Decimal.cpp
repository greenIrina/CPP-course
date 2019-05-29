//
// Created by IrinaT on 5/3/2019.
//

#include "Decimal.h"

long long gcd(long long a, long long b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        } else
        {
            b -= a;
        }
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

void Decimal::swap(Decimal& dec)
{
    std::swap(mNumerator, dec.mNumerator);
    std::swap(mDenominator, dec.mDenominator);
}

void Decimal::applyCompare(Decimal const& dec, long long& num1, long long& num2)
{
    long long _lcm = lcm(mDenominator, dec.mDenominator);
    num1 = mNumerator * (_lcm / mDenominator);
    num2 = dec.mNumerator * (_lcm / dec.mDenominator);
}

//

Decimal::Decimal(long long n, long long d) : mNumerator(n), mDenominator(d)
{}

Decimal::Decimal() : mNumerator(), mDenominator()
{}

double Decimal::toDouble() const
{
    return mNumerator / static_cast<double>(mDenominator);
}

void Decimal::reduce()
{
    long long _gcd = gcd(mNumerator, mDenominator);
    mNumerator /= _gcd;
    mDenominator /= _gcd;
}

long long Decimal::getNumerator() const
{
    return mNumerator;
}

long long Decimal::getDenominator() const
{
    return mDenominator;
}

Decimal::operator bool() const
{
    return mNumerator != 0;
}

Decimal::operator long long() const
{
    return mNumerator / mDenominator;
}

Decimal& Decimal::operator=(Decimal const& dec)
{
    Decimal d(dec);
    swap(d);
    return *this;
}

Decimal& Decimal::operator+=(Decimal const& dec)
{
    long long _lcm = lcm(mDenominator, dec.mDenominator);
    mNumerator = mNumerator * (_lcm / mDenominator) + dec.mNumerator * (_lcm / dec.mDenominator);
    mDenominator = _lcm;
    return *this;
}

Decimal& Decimal::operator-=(Decimal const& dec)
{
    long long _lcm = lcm(mDenominator, dec.mDenominator);
    mNumerator = mNumerator * (_lcm / mDenominator) - dec.mNumerator * (_lcm / dec.mDenominator);
    mDenominator = _lcm;
    return *this;
}

Decimal& Decimal::operator*=(Decimal const& dec)
{
    mNumerator *= dec.mNumerator;
    mDenominator *= dec.mDenominator;
    return *this;
}

Decimal& Decimal::operator/=(Decimal const& dec)
{
    mNumerator *= dec.mDenominator;
    mDenominator *= dec.mNumerator;
    return *this;
}

Decimal& Decimal::operator&=(Decimal const& dec)
{
    mNumerator &= dec.mNumerator;
    mDenominator &= dec.mDenominator;
    return *this;
}

Decimal& Decimal::operator|=(Decimal const& dec)
{
    mNumerator |= dec.mNumerator;
    mDenominator |= dec.mDenominator;
    return *this;
}

Decimal& Decimal::operator<<=(Decimal const& dec)
{
    mNumerator <<= dec.mNumerator;
    mDenominator <<= dec.mDenominator;
    return *this;
}

Decimal& Decimal::operator>>=(Decimal const& dec)
{
    mNumerator >>= dec.mNumerator;
    mDenominator >>= dec.mDenominator;
    return *this;
}

Decimal& Decimal::operator^=(Decimal const& dec)
{
    mNumerator ^= dec.mNumerator;
    mDenominator ^= dec.mDenominator;
    return *this;
}


Decimal& Decimal::operator++()
{
    mNumerator += mDenominator;
    return *this;
}

const Decimal Decimal::operator++(int)
{
    Decimal tmp(*this);
    mNumerator += mDenominator;
    return tmp;
}

Decimal& Decimal::operator--()
{
    mNumerator -= mDenominator;
    return *this;
}

const Decimal Decimal::operator--(int)
{
    Decimal tmp(*this);
    mNumerator -= mDenominator;
    return tmp;
}

Decimal& Decimal::operator*()
{
    return *this;
}

Decimal* Decimal::operator&()
{
    return this;
}

Decimal* Decimal::operator->()
{
    return this;
}

Decimal& Decimal::operator->*(long long num)
{
    mNumerator += num;
    return *this;
}

long long& Decimal::operator[](int ind)
{
    return (ind == 1) ? mDenominator : mNumerator;
}

long long const& Decimal::operator[](int ind) const
{
    return (ind == 1) ? mDenominator : mNumerator;
}

Decimal Decimal::operator,(Decimal dec)
{
    return Decimal(mNumerator, dec.mDenominator);
}

bool Decimal::operator==(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 == num2;
}

bool Decimal::operator!=(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 != num2;
}

bool Decimal::operator<(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 < num2;
}

bool Decimal::operator>(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 > num2;
}

bool Decimal::operator<=(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 <= num2;
}

bool Decimal::operator>=(Decimal const& dec)
{
    long long num1 = 0, num2 = 0;
    applyCompare(dec, num1, num2);
    return num1 >= num2;
}

bool Decimal::operator&(Decimal const& dec)
{
    return (mNumerator == dec.mNumerator & mDenominator == dec.mDenominator);
}

bool Decimal::operator|(Decimal const& dec)
{
    return (mNumerator == dec.mNumerator | mDenominator == dec.mDenominator);
}

bool Decimal::operator&&(Decimal const& dec)
{
    return (mNumerator == dec.mNumerator && mDenominator == dec.mDenominator);
}

bool Decimal::operator||(Decimal const& dec)
{
    return (mNumerator == dec.mNumerator || mDenominator == dec.mDenominator);
}

Decimal Decimal::operator+(Decimal const& dec)
{
    long long _lcm = lcm(mDenominator, dec.mDenominator);
    Decimal d(mNumerator * (_lcm / mDenominator) + dec.mNumerator * (_lcm / dec.mDenominator), _lcm);
    return d;
}

Decimal Decimal::operator-(Decimal const& dec)
{
    long long _lcm = lcm(mDenominator, dec.mDenominator);
    Decimal d(mNumerator * (_lcm / mDenominator) - dec.mNumerator * (_lcm / dec.mDenominator), _lcm);
    return d;
}

Decimal Decimal::operator*(Decimal const& dec)
{
    Decimal d(mNumerator * dec.mNumerator, mDenominator * dec.mDenominator);
    return d;
}

Decimal Decimal::operator/(Decimal const& dec)
{
    Decimal d(mNumerator * dec.mDenominator, dec.mNumerator * mDenominator);
    return d;
}

Decimal Decimal::operator<<(Decimal const& dec)
{
    Decimal d(mNumerator >> dec.mNumerator, dec.mDenominator >> mDenominator);
    return d;
}

Decimal Decimal::operator>>(Decimal const& dec)
{
    Decimal d(mNumerator >> dec.mNumerator, dec.mDenominator >> mDenominator);
    return d;
}

std::ostream& operator<<(std::ostream& out, Decimal const& dec)
{
    return out << dec.mNumerator << "/" << dec.mDenominator;
}

std::istream& operator>>(std::istream& in, Decimal& dec)
{
    char c;
    in >> dec.mNumerator >> c >> dec.mDenominator;
    return in;
}
