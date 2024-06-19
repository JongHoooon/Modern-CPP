#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void speak();
  virtual ~Animal() = default;
private:
  double animalData;
};

class Lion: public Animal
{
public:
  virtual void speak();

private:
  double lionData;
};

int main(void)
{ 
  Animal* polyAnimal = new Lion();
  polyAnimal -> speak();
  delete polyAnimal;
  return 0;
}
