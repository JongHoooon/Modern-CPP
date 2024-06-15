# Inheritance

<br>

## Inheritance Intro

### 사용하는 이유
- class relation
- code reuse
- class interface consistency
  - abstract class
  - interface class
  - pure virtual function
- Dynamic function binding
  - virtual function
  - virtual table

### 접근 권한 키워드
- private 
- public
- protected

```cpp
#include <iostream>
using namespace std;

class A 
{
  public:
    int x;
  protected:
    int y;
  private:
    int z;      
};

class B : public A
{
  // x is public
  // y is protected
  // z is not accessible from B
};

class C : protected A
{
  // x is protected
  // y is protected
  // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
  // x is private
  // y is private
  // z is not accessible from D
};
```

<br>

## Virtual Function

### Constructor / Destructor

- 부모, 자식 Constructor, Destructor 실행 순서

```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  Animal()
  {
    cout << "animal  Constructor" << endl;
  }
  ~Animal()
  {
    cout << "animal Destructor" << endl;
  }
};

class Cat : public Animal
{
public: 
  Cat()
  {
    cout << "cat Constructor" << endl;
  }
  ~Cat()
  {
    cout << "cat Destructor" << endl;
  }
};

int main() {
  Cat cat;
}

/*
animal  Constructor
cat Constructor
cat Destructor
animal Destructor
*/
```

 ```cpp
 int main() {
  Animal * polyCat = new Cat();
  delete polyCat;
}

/*
animal  Constructor
cat Constructor
animal Destructor 
*/
```

> 🚨 이전 코드랑 비교 시 cat의 Destructor 호출되지 않음

Base class의 Destructor 는 다음 2가지 방법으로 선언돼야한다.

- virtual public
- protected 
  - base class를 object로 만들지 않겠다는 뜻(이런 상황이 필요할 때만, 추후 자세히..)


- virtual public destructor
  
```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  Animal()
  {
    cout << "animal  Constructor" << endl;
  }
  // ✨ virtual 키워드 추가
  virtual ~Animal()
  {
    cout << "animal Destructor" << endl;
  }
};

class Cat : public Animal
{
public: 
  Cat()
  {
    cout << "cat Constructor" << endl;
  }
  ~Cat()
  {
    cout << "cat Destructor" << endl;
  }
};

int main() {
  Animal * polyCat = new Cat();
  delete polyCat;
}

/*
animal  Constructor
cat Constructor
cat Destructor
animal Destructor
*/
```

<br>

### virtual
- 상속과 virtual을 통해 run time에 어떤 object를 생성할 지 결정 

```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void speak()
  {
    cout << "Animal" << endl;
  }
  virtual ~Animal()=default;
};

class Cat : public Animal
{
public: 
  virtual void speak()
  {
    cout << "meow~" << endl;
  }
};
 
int main() {
  int i = 0;
  std::cin >> i;
  // dynamic, runtime polymorphism
  Animal * polyAnimal;
  if(i == 1) 
  { 
    polyAnimal = new Cat();
  }
  else 
  {
    polyAnimal = new Animal();
  }
  polyAnimal -> speak();
  delete polyAnimal;
}
```
