#include "Functions.h"
#include <iostream>
using namespace std;
bool IsPrime(int x)
{
    bool _prime = true;
    int i = 2;
    while(i <=x/i)
    {
        int factor = x/i;
        if(factor * i == x)
        {
            cout<<"factor found: " << factor<<endl;
            _prime=false;
            break;
        }
        i = i +1;
    }
    cout<< x << " is ";
    if(_prime)
        cout<<"prime"<<endl;
    else
        cout<<"not prime"<<endl;
        cout<<"not prime"<<endl;
    return _prime;  
}
bool Is2MorePrime(int x)
{
    x = x+2;
    return IsPrime(x);
}

// int & BadFunction()
// {
//     int a = 3;
//     return a;
// }










