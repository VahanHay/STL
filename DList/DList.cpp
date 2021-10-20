#include <iostream>
#include "DList.h"


int main()
{
    DList<int> a;
    a.push_front(5);
    a.push_front(5);
    //a.push_back(90);
    //a.push_back(99);
  /// std::cout << a.empty() << std::endl;
    //a.push_front(2);
  /// std::cout << a.empty() << std::endl;
    
    // a.print();
    // a.push_front(2);
    // a.print();
    // a.pop_front();
    // a.print();
    /* a.pop_front();
       a.print();
    std::cout <<  a.get_size() << std::endl;
    
          a.pop_front();
     std::cout <<  a.get_size() << std::endl;
     a.print();
     std::cout <<   a.front()<< std::endl;
    std::cout <<   a.back()<< std::endl;*/
    //a.clear();
    DList<int> b(a);
    b.print();
    std::cout << b.get_size()<<std::endl;
    std::cout<<a.get_size()<<std::endl;
    a.print();
    b.push_back(23);
   //  a.push_front(105);
    //a.push_back(50);
    //a.push_front(505);
    // a.print();
    // std::cout <<  a.get_size() << std::endl;
    DList<int> d(b);
    d.print();
    d.swap(b);
    std::cout << std::endl;
   // d.print();
    b.insert(1,10);
   // b.clear();
    b.print();
    return 0;
}
