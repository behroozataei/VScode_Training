#ifndef _Resource_H
#define _Resource_H
#include <string>

class Resource 
{
    private:
        std::string name;
    public:
        Resource(std::string n);
        ~Resource(void);
        std::string GetName() const {return name;}
};
#endif