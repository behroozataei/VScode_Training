#include "Person.h"
#include <iostream>

Person::Person(std::string first,
    std::string last, int aribitrary):
    firstname(first),lastname(last),arbitrarynumber(aribitrary),pResource(nullptr)
{  
    std::cout  << "Constructing  " << GetName() << std::endl;
}

Person::Person(const Person& p):firstname(p.firstname),lastname(p.lastname),arbitrarynumber(p.arbitrarynumber),pResource(new Resource(p.pResource->GetName()))
{  
    std::cout  << "Copy Constructing  " << GetName() << std::endl;
}

Person::~Person()
{
    std::cout  << "Destructing  " << GetName() << std::endl;
    delete pResource;


}

std::string Person::GetName() const
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

bool operator<(int i ,const  Person & p)
{
    return i<p.arbitrarynumber;
}
void Person::AddResource()
{
    pResource = new Resource("Resource for " + GetName());
}
Person& Person::operator=(const Person& p)
{
    firstname = p.firstname;
    lastname = p.lastname;
    arbitrarynumber = p.arbitrarynumber;
    pResource = new Resource(p.pResource->GetName());
    std::cout  << "Copy Assignment Constructing  " << GetName() << std::endl;
}

