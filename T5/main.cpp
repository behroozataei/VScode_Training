#include "account.h"
#include <iostream>
using namespace std;
int main()
{
    int arbitrary;
    try
    {
        
        cin>>arbitrary;
        account account1("behrooz","ataei",arbitrary);
        cin>>arbitrary;
        account account("behrooz","ataei",arbitrary);
    }

    catch( invalid_argument& s)
    {
        cout<<"Invalid Argument  "<<s.what()<<endl;
    }

    catch( out_of_range& s)
    {
        cout<<s.what()<<endl;
    }
    catch( exception& s)
    {
        cout<<s.what()<<endl;

    }
    cin>>arbitrary;

}