#include "account.h"
#include <iostream>
using namespace std;
int main()
{
    string Name,FamilyName;
    int arbitrary;
    try
    {   cout<<"Enter Name :";
        cin>>Name;
        cout<<"Enter Family Name :";
        cin>>FamilyName;
        cout<<"Enter Arbitrary :";
        cin>>arbitrary;
        account *Ac1= new account(Name,FamilyName,arbitrary);
        cout<<Name<<" "<<FamilyName<<" "<<arbitrary<<endl;
        
    }
    

    catch( invalid_argument& s)
    {
        cout<<"Invalid Argument "<<s.what()<<endl;
    }

    catch( out_of_range& s)
    {
        cout<<s.what()<<endl;
    }
    catch( exception& s)
    {
        cout<<s.what()<<endl;

    }
    

}