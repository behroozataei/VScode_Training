#include <iostream>
#include "Resource.h"
using namespace std;
Resource::Resource(string n):name(n)
{
    cout<<"Constructing "<<name<<endl;
}

Resource::~Resource(void)
{
    cout<<"Destructing "<<name<<endl;
}