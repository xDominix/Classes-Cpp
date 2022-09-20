#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction& Fraction::operator+=(const Fraction& f)//additional
{
    numerator_ *= f.denominator();
    int temp = denominator_;
    denominator_ *= f.denominator();
    
    numerator_ += f.numerator()*temp;
    
    reduce();

    return *this;
}

Fraction& Fraction::operator*=(const Fraction& f)//additional
{
    numerator_ *= f.numerator();
    denominator_ *= f.denominator();
    
    reduce();

    return *this;
}

Fraction& Fraction::reduce()
{
    int a = std::gcd(numerator_,denominator_);
    numerator_ /= a;
    denominator_ /= a;

    return *this;
}

const Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction newf(f1);
    return (newf+= f2);
}

const Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction newf(f1);
    return (newf*= f2);
}

Fraction& Fraction::operator=(const Fraction& v)
{
    denominator_ = v.denominator_;
    numerator_ = v.numerator_;
    return *this;
}
