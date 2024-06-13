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