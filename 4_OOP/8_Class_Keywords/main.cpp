#include <iostream>
using namespace std;

class Cat
{
public:
  Cat()
  {
    mAge = 0;    
    mName = "cat";
  }
  void age(int age)
  {
    mAge = age;
  }
  int age() const
  {
    return mAge;
  }
  void name(string name)
  {
    mName = move(name);
  }

  /*
  string name() const
  {
    // return by value에 의해 불필요한 복사 발생
    return mName;
  }
  */

  const string& name() const
  {
    return mName;
  }
private:
  int mAge;
  string mName;
};

int main(void) 
{
  const Cat kitty;
  string name = kitty.name();            // deep copy
  const string & nameRef = kitty.name(); // no deep copy
}

// class Cat
// {
// public: 
//   explicit Cat(int age): mAge{age} {};
//   void printAge() const
//   {
//     cout << "age: " << mAge << endl;
//   };
// private:
//   int mAge;
// };

// int main(void) 
// {
//   const Cat kitty = 3;
//   kitty.printAge();
//   return 0;
// }


// class Cat
// {
// public: 
//   Cat(string name): mName{std::move(name)} {};
//   void speak() const
//   {
//     mName = "mutable!";
//     cout << mName << endl;
//   }
// private:
//   mutable string mName;
// };

// int main(void) 
// {
//   const Cat kitty{"kitty"};
//   kitty.speak();
//   return 0;
// }
