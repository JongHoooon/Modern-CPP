/*
C style
C++ Style
Safer C++ Style
*/

#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>

class Cat 
{ 
public:
    Cat()
    {
        std::cout << "meow" << std::endl;
    };
    ~Cat()
    {
        std::cout << "bye" << std::endl;
    };
private:
    int mAge;
};

int main() { 
    // C style heap Cat
    // Cat * catp = (Cat *)malloc(sizeof(Cat));
    // free(catp);

    // Cat * catp = new Cat;
    // delete catp;

    // C style heap Cats(Cat array)
    // Cat * catap = (Cat *)malloc(sizeof(Cat)*5);
    // free(catap);

    // Cat * catap = new Cat[5];
    // delete [] catap;

    // C style heap int
    // int * ip = (int *)malloc(sizeof(int));
    // * ip = 100;
    // free(ip);

    // int * ip = new int;
    // *ip = 100;
    // delete ip;

    // C Style heap array
    // int * iap = (int *)malloc(sizeof(int)*5);
    // iap[0]=100;
    // free(iap);

    // int * iap = new int[5];
    // delete [] iap;

    // C Style로 작성시 constructor, destructor 호출되지 않음
    // C style로 객체를 만들면 안됨, malloc 사용 지양
    // malloc, free -> new, delete 

    // C++ Style로 작성시
    // delete 과정을 까먹으면 destructor 호출되지 않아 memory leak 발생

    // smart_ptr 사용

    // Safer C++ style heap
    // std::unique_ptr<Cat> catp = std::make_unique<Cat>();
    // std::vector<Cat> cats(5);

    // Dynamic Allocation
    std::cout<< "How many cats do u need?" << std::endl;
    int catCount;
    std::cin >> catCount;
    std::vector<Cat> cats(catCount); 
}