// #include <iostream>

// class Cat
// {
// public:
//   Cat()
//   {
//     // std::cout << "constructor" << std::endl;
//     mptr = std::make_unique<Object>();
//   }
//   ~Cat()
//   {
//     std::cout << "destructor" << std::endl;
//   }
//   void speak()
//   {
//     std::cout << "meow" << std::endl;
//   }

// private:
//   int mAge;
//   std::unique_ptr<Object> mptr:
// };

// int main()
// {
//   Cat kitty;
//   kitty.speak();
//   return 0;
// }

#include <iostream>

class Cat
{
public:
  Cat()
  {
    mAge = 1;
  }
  Cat(int age)
  {
    mAge = age;
  }
private:
  int mAge;
};

class Zoo
{
public:
  /*
  Zoo(int kittyAge)
  {
    mKitty = Cat(kittyAge); // 임시 object(고양이)가 만들어지고 값을 할당하면서 사라짐
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
