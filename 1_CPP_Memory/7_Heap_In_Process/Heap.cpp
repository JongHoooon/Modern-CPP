#include <iostream>

// int main() 
// {
//     int allocCount=0;
//     std::cout << "how many?" << std::endl;
//     std::cin >> allocCount;

//     for (int i=0 ; i<allocCount ; i++) 
//     {
//         int * ip = new int[250]; // 1kb
//         std::cout << "men" << std::flush;
//         // delete [] ip;
//     }

//     return 0;
// }

// valgrind -> memory leak 확인 tool

int main()
{
    int * ip = new int[250]; // 1kb
    return 0;
}

