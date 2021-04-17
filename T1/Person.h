#include <string>
#include "Resource.h"
#ifndef _Person_H
#define _Person_H
class Person
{
    private:
        std::string firstname;
        std::string lastname;
        int arbitrarynumber;
        Resource *pResource;
    public:
        Person(std::string first,
            std::string last,
            int arbitrary);
        Person(const Person &p);

        std::string GetName() const;   
        int GetNumber() const {return arbitrarynumber;}
        void SetNumber(int number){ arbitrarynumber = number;} 
        bool operator < (const Person& P) const;
        bool operator < (int i) const;
        bool operator >>(Person& p);
        friend bool operator <(int i, const Person & p);
        Person & operator = (const Person& p);
        void AddResource();
        Person();
        ~Person();
};
//bool operator <(int i, Person & p);
#endif