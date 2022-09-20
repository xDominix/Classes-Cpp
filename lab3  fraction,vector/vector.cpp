// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include "vector.h"

Vector::Vector(const Vector&v):data_((Fraction*)malloc(v.capacity_*sizeof(Fraction))),size_(v.size()),capacity_(v.capacity())
{
    for(size_t i =0; i<v.size(); i++)
    {
        data_[i]=v.data_[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    delete[] data_;
    data_= (Fraction*) malloc(v.capacity()*sizeof(Fraction));
    size_= v.size();
    capacity_ = v.capacity();
    
    for(size_t i =0;i<v.size();i++)
    {
        data_[i]=v.data()[i];
    }
    return *this;
}

void Vector::push_back(const Fraction f)
{
    if(size_<capacity_)
    {
        data_[size_]= f;
        size_+=1;
    }
    else
    {
        Fraction* newdata = (Fraction*)malloc((size_+1)*sizeof(Fraction));
        
        for(size_t i =0; i<size_; i++)
        {
            newdata[i]=data_[i];
        }
        newdata[size_]=f;
        
        data_=newdata;
        size_+=1;
        capacity_=size_;
    }

   
}

Vector::Vector(Vector&& v) noexcept :data_(v.data_),size_(v.size()),capacity_(v.capacity()) 
{
    v.data_ = nullptr;
    v.size_=0;
    v.capacity_=0;
}

Vector& Vector::operator=(Vector&& v) noexcept
{
    std::swap(data_,v.data_);
    std::swap(size_,v.size_);
    std::swap(capacity_,v.capacity_);
    return *this;
}