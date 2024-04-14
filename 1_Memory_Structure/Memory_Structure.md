# Memory Structure

> high level, low level 메모리 모델에서 데이터가 어떻게 저장되는지
> 
> Data가 Stack과 Heap에 저장되는 이유
> 
> 메모리 leak
> 
> 메모리 leak 방지 방법


## Variables in Memory

> Stack

- 컴퓨터는 위에서 몇번째 떨어져 있는지를 기준으로 변수가 어디 저장됐는지 찾음

```cpp
int main()
{
    int a = 0;
    int b = 3;
    int c = a+b;
    double d = 2.5;
}
```

<img src = "image.png" width = "60%">

<br>

## Variable Types 1

- 각 타입은 타입에 맞는 메모리 공간을 차지한다.

https://en.cppreference.com/w/cpp/language/types

https://en.cppreference.com/w/cpp/types/integer

<br>

## Variable Types 2

> Struct, Class

### Struct
- 내부 변수에 따라 크기 결정
- Memory Access 패턴 때문에 Compiler가 사이에 패딩을 넣어줘 크기가 커질 수 있다.

### Class
- 내부 변수에 따라 크기 결정

### Pointer
- 64비트 환경에서 주소를 가리키기위해서 8바이트 크기를 갖음

<br>

## Stack Frame
- 메모리는 Stack Frame 단위로 쌓아감, Stack Frame은 fuction 단위로 나뉘어 진다.
- argument 정보, return address 정보 들도 포함된다.

```cpp
void foo()
{
    int a;
    int b;
};

class Cat
{ 

};

class Dog
{ 

};

void bar() 
{
    Cat cat;
    Dog dog;
};

int main()
{
    int a;
    double b;

    foo();
    bar();

    return 0;
}
```

<img src = "image-1.png" width = "60%">

```cpp
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
```

> this: 현제 object의 address를 가리키는 키워드
> this를 사용해 member variable을 controll한다.

<img src = "image-2.png" width = "60%">
