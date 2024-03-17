#include <iostream>

struct ST
{ 
    long a;     // 8bytes
    int b;      // 4bytes
    short c;    // 2bytes
};

class Cat 
{ 
    public:
        void printCat();    // class size에 영향을 미치지 않음
    private:
        int age;            // 4bytes
        float weight;       // 4bytes
};

int foo(int arg) 
{
    int a = 0;
    int b = 1;
    int d = arg+a+b;
    return d;
}

int main() 
{
    // 내부 변수에 따라서 사이즈 결정
    // 8 + 4 + 2 가 아니라 16bytes를 차지함
    // 메모리 에세스 패턴때문에 컴파일러가 사이에 패딩을 넣어줌
    std::cout << sizeof(ST) << std::endl;

    std::cout << sizeof(Cat) << std::endl;
    Cat cat1;
    Cat cat2;

    Cat * catPtr = &cat1;           // 8 bytes (64bit) 64비트 환경에서 주소를 나타내려면 항상 64비트(8바이트이다.)
    std::cout << sizeof(catPtr) << std::endl;

    int a;
    double b;
    bool c;

    return 0;
}