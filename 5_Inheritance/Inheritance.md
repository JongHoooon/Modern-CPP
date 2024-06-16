# Inheritance

<br>

## 1. Inheritance Intro

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

## 2. Virtual Function

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

<br>

## 3. Virtual Table

```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  void speak()
  {
    cout << "Animal" << endl;
  }
  // virtual ~Animal()=default;
private:
  double height; // 8bytes
};

class Cat : public Animal
{
public: 
  void speak()
  {
    cout << "meow~" << endl;
  }
private:
  double weight; // 8bytes + 8bytes
};
 
int main() {
  cout << "Animal size: " << sizeof(Animal) << endl;
  cout << "Cat size: " << sizeof(Cat) << endl;
}
/*
Animal size: 8
Cat size: 16
*/
```

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
  // virtual ~Animal()=default;
private:
  double height; // 8bytes
};

class Cat : public Animal
{
public: 
  void speak() override
  {
    cout << "meow~" << endl;
  }
private:
  double weight; // 8bytes + 8bytes
};
 
int main() {
  cout << "Animal size: " << sizeof(Animal) << endl;
  cout << "Cat size: " << sizeof(Cat) << endl;
}
/*
Animal size: 16
Cat size: 24
*/
```

- virtual 키워드를 사용하면 virtual table address 정보가 추가로 들어가 size가 커진다.

<img src = "image.png" width = "80%">

<br>

## 4. Pure Virtual Function

### Pure Virtual Function
> function implementation 이 없는 virtual function 
- object 생성이 불가능함

```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void speak() = 0;
  virtual ~Animal()=default;
private:
  double height; // 8bytes
};

class Cat : public Animal
{
public: 
  /* 🚨 unimplemented pure virtual method 'speak' in 'Cat' */
  // void speak() override
  // {
  //   cout << "meow~" << endl;
  // }
private:
  double weight; // 8bytes + 8bytes
};
 
int main() {
  Cat cat;
}
```

### Abstract class
> Pure Virtual Function을 1개라도 갖고있는 class

### Interface class
> implementation X, only pure virtual function
> member variable X

- 구현부가 있으면 추후 derived class에 원하지 않는 구현부가 상속될 수 있음
  - 원하지 않는 구현부가 절달될 때 virtual, override 키워드를 붙여 override하도록 수정해야함
- member varible이 있으면 불필요한 member varible들이 상속될 수 있음

<br>

- derived class에서 중복이 되는 메소드가 있을 때는 Interface class와 Implementation class를 구현해 다중상속을 통해 해결 


<br>

## Multiple Inheritance
