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

class SuperCat: public Cat
{
public:
  void speak() override
  {
    cout << "test" << endl;
  }
};
 
int main() {
  cout << "Animal size: " << sizeof(Animal) << endl;
  cout << "Cat size: " << sizeof(Cat) << endl;
}
