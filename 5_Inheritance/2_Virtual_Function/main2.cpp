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