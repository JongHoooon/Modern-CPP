#include <iostream>
using namespace std;

class Animal 
{
public: 
  Animal()=default;
  Animal& operator=(Animal other) = delete;
  virtual void speak()
  {
    cout << "Animal" << endl;
  }
  virtual ~Animal() = default;
protected:
  Animal(const Animal & other) = default;

private:
  double animalData = 0.0;
};

class Cat : public Animal
{
public:
  Cat(double d): catData{d} { }
  void speak() override
  {
    cout << "meow~" << endl;
  }
private:
  double catData;
};

void f(Animal animal) { 
  animal.speak();
}

int main(void)
{ 
  Cat kitty{1.0};
  Cat nabi{kitty};

  // Animal& animalRef = kitty;
  // animalRef.speak();

  // cout << "-----------------------------" << endl;

  // Animal animalObj = kitty; // copy constructor
  // animalObj.speak();

  return 0;
}
