#include <iostream>

void hello() 
{
#ifdef NAME
    std::cout << "Hello, " << NAME << "!" << std::endl;
#else
    std::cout << "Hello, stranger" << std::endl;
#endif
}