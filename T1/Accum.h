#pragma once
#include "Person.h"
template <class T>
class Accum
{
    private:
        T total;
    public:
        Accum(T start):total(start){};
        T operator+=(const T& t){ total = total + t;};
        T GetTotal(){ return total;};
};

template <>
class Accum<Person>
{
    private:
        int total;
    public:
        Accum(int start):total(start){};
        int operator+=(Person& t){ total = total + t.GetNumber();};
        int GetTotal(){ return total;};
        
};