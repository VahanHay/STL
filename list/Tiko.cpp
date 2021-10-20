// MyList.cpp :
#include <iostream>
#include <string>
#include "1.h"
int main()
{
    MyList<int> list;
    list.push_back(5);
    list.push_back(6);
    //std::cout<<list.empty();
    //std::cout << list.size();
    //list.clear();
   // list.print();
    list.assign(3, 8);
    for (MyList<int>::Iterator iterator = list.begin();
        iterator != list.end(); iterator++)
    {
        std::cout << *iterator << " ";
    }
    /*std::cout << list << std::endl;
    MyList<int> list1(list);
    MyList<std::string> L2;
    //MyList<std::string> L5;
    //L5.push_back("kkk");
    //L5.print();
    L2 = { "dfd","dfdf","dfdf" };
    MyList<std::string> l3{"dfd","dfdf","dfdf"};
    L2.print();
    //std::cout << list1 << std::endl;
    //std::cout << L2 << std::endl;
    //std::cout << l3 << std::endl; */
    return 0;
}