#include <string>
#ifndef _Person_H
#define _Person_H
class Person
{
    private:
        std::string firstname;
        std::string lastname;
    public:
        int arbitrarynumber;
    public:
        Person(std::string first,
            std::string last,
            int arbitrary);

        std::string GetName();   
        int GetNumber(){return arbitrarynumber;}
        void SetNumber(int number){ arbitrarynumber = number;} 
        bool operator < (const Person& P) const;
        bool operator < (int i) const;
        bool operator >>(Person& p);
        friend bool operator <(int i, Person & p);
        Person();
        ~Person();
};
//bool operator <(int i, Person & p);
#endif