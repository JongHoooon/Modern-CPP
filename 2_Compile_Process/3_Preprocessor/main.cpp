#define MAX_UINT16 65535
#define MAX(a, b) (((a)>(b))?(a):(b))
#define ABCD 2
#include <iostream>
 
int main()
{
// #ifdef ABCD
//     std::cout << "1: yes\n";
// #else
//     std::cout << "1: no\n";
// #endif
 
// #ifndef ABCD
//     std::cout << "2: no1\n";
// #elif ABCD == 2
//     std::cout << "2: yes\n";
// #else
//     std::cout << "2: no2\n";
// #endif 

    std::cout << MAX_UINT16 << std::endl;
    std::cout << MAX(10, 100) << std::endl;

    // pre defined macros
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
    std::cout << __DATE__ << std::endl;
    std::cout << __TIME__ << std::endl;
}
