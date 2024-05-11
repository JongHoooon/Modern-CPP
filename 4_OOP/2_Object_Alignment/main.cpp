#include <iostream>

// class Cat
// {
// public: 
//     void speak();
// private:
//     int i4a;    // 4bytes
//     double d8;  // 8bytes
//     int i4b;    // 4bytes
// };

// class Cat
// {
// public: 
//     void speak();
// private:
//     char c1;    // 1byte
//     int i4a;    // 4bytes
//     int i4b;    // 4bytes
//     double d8;  // 8bytes
// };

class alignas(32) Cat
{
public: 
    void speak();
private:
    char c1;    // 1byte
    int i4a;    // 4bytes
    int i4b;    // 4bytes
    double d8;  // 8bytes
};

Cat staticCat;

int main()
{
    std::cout << sizeof(Cat) << std::endl;

    Cat stackCat;

    Cat * heapCatPtr = new Cat();
    delete heapCatPtr;
    // prefer smartPtr

    return 0;
}
