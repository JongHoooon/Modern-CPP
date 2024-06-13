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
