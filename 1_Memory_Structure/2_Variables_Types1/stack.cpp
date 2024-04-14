#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    static_assert(sizeof(int)==4, "int is 4bytes");
    int a = 0;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(a) << std::endl;

    std::cout << sizeof(int8_t) << std::endl;
    std::cout << sizeof(int64_t) << std::endl;

    // array
    int arr[10];
    std::cout << sizeof(arr) << std::endl;

    // array2
    std::array<int, 5> ia;
    std::cout << sizeof(ia) << std::endl;

    uint64_t ui8;
    float f4;
    std::array<uint8_t, 5> uia5;

    uint64_t * ui64ptr = &ui8;
    std::cout << sizeof(ui64ptr) << std::endl;  
    std::cout << (uint64_t)ui64ptr << std::endl;

    return 0;
}