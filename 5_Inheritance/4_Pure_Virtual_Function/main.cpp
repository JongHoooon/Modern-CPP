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
  void speak() override
  {
    cout << "meow~" << endl;
  }
private:
  double weight; // 8bytes + 8bytes
};
 
int main() {
  Cat cat;
}
