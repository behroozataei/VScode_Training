#include <string>
#include "Resource.h"
#ifndef _Person_H
#define _Person_H
#include <memory>

class Person
{
    private:
        int arbitrarynumber;
        std::shared_ptr<Resource> pResource;
    protected:
        std::string firstname;
        std::string lastname;
    public:
        Person(std::string first,
            std::string last,
            int arbitrary);
       // Person(const Person &p);

        virtual std::string GetName() const;   
        int GetNumber() const {return arbitrarynumber;}
        void SetNumber(int number){ arbitrarynumber = number;} 
        bool operator < (const Person& P) const;
        bool operator < (int i) const;
        bool operator >>(Person& p);
        friend bool operator <(int i, const Person & p);
       // Person & operator = (const Person& p);
        void AddResource();
        std::string GetResourceName() const { return
            pResource->GetName();}
        Person();
        ~Person();
};
//bool operator <(int i, Person & p);
#endif