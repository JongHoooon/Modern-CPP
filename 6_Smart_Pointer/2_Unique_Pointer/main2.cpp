#include <iostream>
#include <memory>
using namespace std;

class Cat : public Animal
{ 
public: 
  Cat(): mAge{0}
  {
    cout << "cat constructor" << endl;
  }
  ~Cat()
  {
    cout << "cat destructor" << endl;
  }

private:
  int mAge;
};

class Dog : public Animal
{};

class Zoo
{
public:
  Zoo(int n)
  {
    if(n==1)
    { 
      mAnimal = make_unique<Cat>();
    } 
    else 
    { 
      mAnimal = make_unique<Dog>();
    }
  }

private:
  unique_ptr<Animal> mAnimal;
}

int main(void) { 
  return 0;
}
