# OOP

<br>

## 1. OOP Intro

### C++ multi paradigm
- procedural
- functional
- OOP
- generic

<br>

### OOP
- Abstraction
- Encapsulation
- Inheritance
- Polymorphism
  - funcion overloading (static)
  - function overriding (dynamic)

<br>
<br>

## 2. Object Alignment

```cpp
#include <iostream>

class Cat
{
public: 
  void speak();
private:
  int mAge;
};

Cat staticCat;

int main()
{
  std::cout << sizeof(Cat) << std::endl;
  // 4
  Cat stackCat;

  Cat * heapCatPtr = new Cat();
  delete heapCatPtr;
  // prefer smartPtr

  return 0;
}
```

<img src = "image.png" width = "80%">

<br>

### memory alignmnet rule
- member variable은 그 size의 배수의 위치에서 시작해야한다.
- object의 전체 size는 가장 큰 member variable size의 배수에서 끝나야한다.

<br>

```cpp
class Cat
{
public: 
  void speak();
private:
  double d8;  // 8bytes
  int i4a;    // 4bytes
  int i4b;    // 4bytes
  /*
  16bytes
  */
};
```

```cpp
class Cat
{
public: 
  void speak();
private:
  int i4a;    // 4bytes
  double d8;  // 8bytes
  int i4b;    // 4bytes
  /*
  24bytes
  */
};
```

<img src = "image-1.png" width = "80%">

<br>

```cpp
class Cat
{
public: 
  void speak();
private:
  char c1;    // 1byte
  int i4a;    // 4bytes
  int i4b;    // 4bytes
  double d8;  // 8bytes
};
```

<img src = "image-2.png" width = "80%">

### False Sharing
- parallel programming 시 Cashe Line 라는 hardware적 구조에 따라 data가 64bytes 단위로 잘라지고 한 블락이 각각 갈라져 다른 core로 들어가는 상황
- alignas 키워드를 사용해 방지한다.
- [alignas🔗](https://en.cppreference.com/w/cpp/language/alignas)

```cpp
class alignas(32) Cat // <-- 32bytes로 변환해 false sharing 방지
{
public: 
  void speak();
private:
  char c1;    // 1byte
  int i4a;    // 4bytes
  int i4b;    // 4bytes
  double d8;  // 8bytes
};
```

<br>

## 3. Static Members in Class

1. static member function
2. static member variable
3. static variable in a function

- [cpp reference static](https://en.cppreference.com/w/cpp/keyword/static)

<br>

### static member function
- static은 object의 address를 가르키는 this와 바인딩되어있지 않다.
  - object를 생성하지 않아도 호출할 수 있다.
  - object를 가르킬 수 없어 static 함수에서 member variable에 접근할 수 없다.
  
```cpp
class Cat
{
public:
  void speak()
  {
    count++;
    std::cout << count << "meow" << std::endl;
  };
  static int count;
  static void staticSpeak()
  {
    std::cout << "CAT!" << std::endl;
    // speak(); <-- static 함수는 member 변수와 memeber 함수를 호출할 수 없다.
  };
private:
  int Age;
};
```

### static member variable
- 프로그램이 실행되기 전에 초기화를 시켜줘야한다.
- 메모리의 static 영역에 생성돼 서로 다른 object에서 공유한다.

```cpp
class Cat
{
public:
  void speak()
  {
    count++;
    std::cout << count << "meow" << std::endl;
  };
  static int count;
  static void staticSpeak()
  {
    std::cout << "CAT!" << std::endl;
  };
private:
  int Age;
};

int Cat::count = 0;
```

<img src = "image-3.png" width = "50%">

### static variable in a function
- speak() 메소드에서만 사용돼 count를 speak() 메소드 안으로 이동
- 메모리의 static 영역에 생성돼 서로 다른 object에서 공유한다.
- 초기화 시점? 추후 학습

```cpp
class Cat
{
public:
  void speak()
  {
    static int count = 0;
    count++;
    std::cout << count << "meow" << std::endl;
  };
  static void staticSpeak()
  {
    std::cout << "CAT!" << std::endl;
  };
private:
  int Age;
};
```

<br>

## 4. Member Init List

```cpp
#include <iostream>

class Cat 
{
public:
  Cat()
  {
    std::cout << "constructor" << std::endl;
    mptr = std::make_unique<Object>();
  }
  ~Cat()
  {
    std::cout << "destructor" << std::endl;
  }
  void speak()
  {
    std::cout << "meow" << std::endl;
  }
private:
  int mAge;
  std::unique_ptr<Object> mptr:
  Object obj;
};

int main() 
{
  Cat kitty;
  kitty.speak();
  return 0;
}
```

![alt text](image-4.png)

- Assembly 코드의 call 명령어를 확인해 보면 constructor, destructor 가 함수처럼 실행된 것을 확인 가능
- heap에 object 생성시
  - constructor에서 heap에 할당, destructor에서 할당 해제 지양
  - smart pointer 사용
  - object가 너무 크지 않다면 member object 생성

### Member Init Lists

```cpp
#include <iostream>

class Cat
{
public:
  /*
  Cat()
  {
    mAge = 1;
  }
  Cat(int age)
  {
    mAge = age;
  }
  */
  Cat():mAge(1){};
  Cat(int age):mAge(age){};
private:
  int mAge;
};

class Zoo
{
public:
  /*
  Zoo(int kittyAge)
  {
    mKitty = Cat(kittyAge); // 임시 object(고양이)가 만들어지고 값을 할당하면서 사라짐(1살 -> 5살)
  }
  */
  Zoo(int kittyAge): mKitty(Cat(kittyAge)) // 멤버 이니셜라이저 리스트를 사용해 임시 object(고양이)가 만들어지지 않음
  {}
private:
  Cat mKitty;
};

int main()
{
  return 0;
}
```

> [cpp reference member init list](https://en.cppreference.com/w/cpp/language/constructor)

<br>

## 5. copy/move Constructor

- 컴파일러가 알아서 만들어주는 메소드들
  1. Constructor
  2. Destructor
  3. copy/move Constructor
  4. copy/move Assignment

- member variable로 pointer를 활용해 resource를 관리하게 되면 constructor를 제외한 메소드들을 구현해줘야한다.

> [rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)

- copy constructor
  - 기존 object의 정보를 copy해 새로운 object를 만들 때 호출되는 생성자
- move constructor
  - 기존 object의 정보를 move해 새로운 object를 만들 때 호출되는 생성자
  - 기존 object의 정보는 새로운 object에 ownership을 뺏긴다.
  
```cpp
#include <iostream>
#include <string>
using namespace std;

class Cat 
{ 
public:
  Cat() = default; // default constructor 명시
  Cat(string name, int age):mName{std::move(name)}, mAge{age}
  {
    cout << mName << " constructor" << endl;
  };
  ~Cat()
  {
    std::cout << mName << " destructor" << endl;
    // delete mPtr;
  }
  Cat(const Cat& other): mName{other.mName}, mAge{other.mAge}
  {
    cout << mName << " copy constructor" << endl;
  }
  Cat(Cat&& other):mName(std::move(other.mName)), mAge{other.mAge} // mName 의 소유권을 뺏어온다.
  {
    cout << mName << " move constructor" << endl;
  }
  void print()
  {
    cout << mName << " " << mAge << endl;
  }

private:
  string mName;
  int mAge;
  // char * mPtr;
};

int main(void) { 
  Cat kitty{"kitty", 1};
  Cat kitty2{kitty};  // copy constructor: 권장 방법
  // Cat kitty3 = kitty; // copy constructor
  Cat kitty3{std::move(kitty)}; // move constructor
  return 0;
}

/*
kitty constructor
kitty copy constructor
kitty move constructor
kitty destructor
kitty destructor
 destructor <- 소유권을 빼껴 이름이 없다.
*/
```

<br>

## 6. copy/move Assignment

```cpp
#include <iostream>
#include <string>
using namespace std;

class Cat 
{ 
public:
  /*
  // 사용못하게 막을 수 있음!
  Cat() = delete;
  Cat(const Cat& other) = delete;
  Cat& operator=(const Cat& other) = delete;
  */

  Cat() = default; // default constructor 명시
  Cat(string name, int age):mName{std::move(name)}, mAge{age}
  {
    cout << mName << " constructor" << endl;
  };
  ~Cat() noexcept
  {
    std::cout << mName << " destructor" << endl;
    // delete mPtr;
  }
  Cat(const Cat& other):mName{other.mName}, mAge{other.mAge}
  {
    cout << mName << " copy constructor" << endl;
  }
  Cat(Cat&& other) noexcept :mName(std::move(other.mName)), mAge{other.mAge} // mName 의 소유권을 뺏어온다.
  {
    cout << mName << " move constructor" << endl;
  }
  Cat& operator=(const Cat& other) noexcept
  {
    if(&other == this) // member variable로 pointer를 활용해 resource를 관리하는 경우 발생할 수 있는문제 예방
    {
      return * this;
    }
    mName = other.mName;
    mAge = other.mAge;
    cout << mName << " copy assignmnet" << endl;
    return *this;
  }
  Cat& operator=(Cat&& other) noexcept
  {
    if(&other == this) // member variable로 pointer를 활용해 resource를 관리하는 경우 발생할 수 있는문제 예방
    {
      return * this;
    }
    mName = std::move(other.mName);
    mAge = other.mAge;
    cout << mName << " move assignmnet" << endl;
    return *this;
  }
  void print()
  {
    cout << mName << " " << mAge << endl;
  }

private:
  string mName;
  int mAge;
  // char * mPtr;
};

int main(void) { 
  Cat kitty{"kitty", 1};
  Cat nabi{"nabi", 2};

  /*
  kitty = nabi;
  kitty.print(); // copy assignment
  */

  /*
  kitty = std::move(nabi); // move assignment
  kitty.print();
  nabi.print();
  */

  /*
  kitty = kitty; 
  kitty = std::move(kitty);
  // 문제가 발생할 수 있음!
  */
  return 0;
}
```