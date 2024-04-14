#include <iostream>

// void foo()
// {
//     int a;
//     int b;
// };

// class Cat
// { 

// };

// class Dog
// { 

// };

// void bar() 
// {
//     Cat cat;
//     Dog dog;
// };

// int main()
// {
//     int a;
//     double b;

//     foo();
//     bar();

//     return 0;
// }

// stack frame 단위로 쌓아감 -> 이 단위는 function 단위이다.
// stack은 변수 단위로 쌓이지 않는다
// stack frame을 쌓아가는 과정에서 argument값 전달 return address, net in structor address, 

class Cat
{
    public:
        Cat() 
        { 
            m_age = 1;
        };
        ~Cat();
        void addAge(int arg)
        {
            m_age += arg;
        };
    private:
        int m_age;
};

int main()
{
    Cat cat;
    cat.addAge(10);

    return 0;
}

// this -> 현제 object의 address를 가르킴
// argument, return address, member variable(this)(필요시) 같이 올라감