#include "Person.h"
#include <iostream>

Person::Person(std::string first,
    std::string last, int aribitrary):
    firstname(first),lastname(last),arbitrarynumber(aribitrary)
{  
    std::cout  << "Constructing  " << GetName() << std::endl;
}

Person::~Person()
{
    std::cout  << "Distructing  " << GetName() << std::endl;


}

std::string Person::GetName()
{
    return firstname + " " + lastname;
}

bool Person::operator<(const Person& p) const
{
    return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator< (int i) const
{
    return arbitrarynumber < i;
}

bool Person::operator>>(Person & p)
{
    return arbitrarynumber > p.arbitrarynumber;
} 

bool operator<(int i , Person & p)
{
    return i<p.arbitrarynumber;
}

