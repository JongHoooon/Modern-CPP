# Smart Pointer

## Smart Pointer Intro

- unique pointer
- shared pointer

- RAII(Resource Acquisition Is Initialization.)
> [cpp reference RAII](https://en.cppreference.com/w/cpp/language/raii)

<br>

- resource의 life cycle과 object의 life cycle을 일치시킨다. -> memory leak 방지
  - object: smartPtr
  - resource: heap memory, thread, file access, mutex, db connection..

<br>

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Cat
{
public: 
  Cat(int age): mAge{age}
  {
    cout << "cat constructor" << endl;
  };
  ~Cat()
  {
    cout << "cat destructor" << endl;
  }

private:
  int mAge;
};

int main(void)
{
  // Cat kitty{1};

  // Cat * catPtr = new Cat{3};
  // delete catPtr;

  unique_ptr<Cat> catPtr = make_unique<Cat>(3); // delete 처리하지 않아도 destructor 호출

  return 0;
}
/*
cat constructor
cat destructor
*/
```

<br>

- unique pointer의 life cycle은 **scope base lifecycle** 이다.

```cpp
int main(void)
{
  cout << "before scope" << endl;
  { 
    unique_ptr<Cat> catPtr = make_unique<Cat>(3);
  }
  cout << "after scope" << endl;
  return 0;
}
/*
before scope
cat constructor
cat destructor
after scope
*/
```

- vector 기반 array의 메모리 leak 방지

```cpp
void foo()
{ 
  cout << "foo function" << endl;
  Cat * cats = new Cat[5];
  cout << "foo function end" << endl;
  delete [] cate;
}
```

```cpp
void foo()
{ 
  cout << "foo function" << endl;
  vector<Cat> cats(5);
  cout << "foo function end" << endl;
}
```

<br>

## Unique Pointer

- Exclusive Ownership
하나의 object를 단 하나의 pointer만 가르킬 수 있다.

```cpp
#include <iostream>
using namespace std;

class Cat
{
public: 
  Cat(): mAge{0}
  {
    cout << "cat constructor" << endl;
  };
  ~Cat()
  {
    cout << "cat destructor" << endl;
  };

private:
  int mAge;
};

void foo(Cat * ptr)
{ 
  Cat * catPtr = ptr;
  delete catPtr;
};

int main(void)
{
  Cat * catPtr = new Cat();
  Cat * catPtr1 = catPtr;
  foo(catPtr);
  delete catPtr;
}
/*
cat constructor
cat destructor
cat destructor
*/
```

- destructor가 2번 실행되는 사고가 발생할 수 있다.

```cpp
void foo(Cat * ptr)
{ 
  unique_ptr<Cat> catPtr = make_unique<Cat>();
  unique_ptr<Cat> catPtr1 = catPtr;   // 🚨 하나의 object는 한개의 Pointer만 가르킬 수 있다.
};
```

```cpp
void foo(Cat * ptr)
{ 
  unique_ptr<Cat> catPtr = make_unique<Cat>();
  unique_ptr<Cat> catPtr1 = std::move(catPtr); // move를 사용해 소유권을 넘겨줘야함
};
```

<br>

- class 에서 dynamic polymorphism으로 member variable로 pointer를 가져야할 때 

```cpp
class Cat : public Animal
{ 
public: 
  Cat(): mAge{0}
  {
    cout << "cat constructor" << endl;
  }
  ~Cat()
  {
    cout << "cat destructor" << endl;
  }

private:
  int mAge;
};

class Dog : public Animal
{};

class Zoo
{
public:
  Zoo(int n)
  {
    if(n==1)
    { 
      mAnimal = new Cat();
    } 
    else 
    { 
      mAnimal = new Dog();
    }
  }
  // member variable 로 pointer를 갖고 있어
  // rule of three, copy/move.. 준수 해야함

private:
  Animal * mAnimal; // class 외부 object를 가리킬 수 있다.
}

int main(void) { 
  return 0;
}
```

- unique pointer 사용해 1개의 object에 1개의 pointer만 카리킬 수 있도록 개선
  - rule of three 고려 X
  - member variable pointer가 class 외부의 object를 가리킬 수 없다.

```cpp
class Zoo
{
public:
  Zoo(int n)
  {
    if(n==1)
    { 
      mAnimal = make_unique<Cat>();
    } 
    else 
    { 
      mAnimal = make_unique<Dog>();
    }
  }

private:
  unique_ptr<Animal> mAnimal;
}
```