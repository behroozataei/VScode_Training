#include <iostream>
#include <vector>
#include <map>
#include "Person.h"
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include <complex>
#include <numeric>
#include <random>
#include <regex>
#include <cmath>

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(9);
    v.push_back(2);

    for(auto i = v.begin(); i != v.end(); i++)
        std::cout<< *i <<" ";

    std::cout<<std::endl;

    for(auto i = v.rbegin(); i != v.rend(); i++)
        std::cout<< *i <<" ";
    std::cout<<std::endl;

    std::map<int,Person> pepole;
    

    std::vector<Person *> vp;
    Person Kate("Kate", "Greogy", 123);
    Person Someone("someone", "else", 456);
    vp.push_back(&Kate);
    vp.push_back(&Someone);

    std::sort(v.begin(),v.end());
    std::for_each(v.begin(),v.end(),[](int i){ std::cout <<i << " ";});
    std::cout<<std::endl;

    std::vector<int> v2;
    std::transform(v.begin(),v.end(),std::back_inserter(v2),[](int i){return i*i*i;});
    std::for_each(v2.begin(),v2.end(),[](int i){ std::cout <<i << " ";});
    std::cout<<std::endl;

    std::vector<double> v3;
    std::transform(v.begin(),v.end(),std::back_inserter(v3),[](int i)->double{
        if(i%2==0)
            return i*i*i;
        else
            return i/2.0;
        });

    std::for_each(v3.begin(),v3.end(),[=](double i){ std::cout <<i << " ";});
    std::cout<<std::endl;

    auto y = [] (int first, int second)
    {
        return first + second;
    };

    return 0;

}
