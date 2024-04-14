
// Stack - alloc / disalloc 이 빠르다
// Heap - alloc / disaclloc 이 느리다(멀티 스레딩, ..), Dynamic allocation 가능

#include <array>
#include <vector>
#include <iostream>

class Cat
{
    public:
    private:
        int m_age;
};

// int main()
// { 
//     int a[5];
//     int a[20];
//     std::array<int, 300> a;         // 1.2kb
//     std::array<int, 500000> b;      // 2mb
//     std::vector<int> b(500000);     // 2mb

    // Cat cat; // stack
    // std::vector<int> b(500000);     // 2mb (heap)
    // std::vector<Cat> cats(100000);

    // int count;
    // std::cin >> count;
    // std::vector<Cat> dynamicCats(count); // heap
// }

// void foo(int num)
// { 
//     std::vector<Cat> cats(num);

//     // do some computation over cats.
// }

// bool bar(int num)
// {
//     constexpr int maxCats = 1000; // constexpr 상수라고 명시
//     if(1000<num)
//     {
//         return false;
//     }
//     std::array<Cat, maxCats> cats;
//     // do some computation over cats
// }

// int main() 
// { 
//     int count;
//     std::cin >> count;
//     foo(count);

    // what if we need performance critical cats?

    // std::array (stack array)
    // std::vector (heap array)
// }

// static(global)

int ga=0;

int main()
{
    int sa = 0;
    std::cout << "&sa : " << (long)&sa << std::endl;

    int * hap = new int;
    std::cout << "&hap : " << (long)hap << std::endl;

    // Prefer Smart Pointer
    delete hap;
    std::cout << "&ga : " << (long)&ga << std::endl;
    
    return 0;
}