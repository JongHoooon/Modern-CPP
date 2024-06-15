#include <iostream>
using namespace std;

class Animal
{
public:
  Animal()
  {
    cout << "animal  Constructor" << endl;
  }
  virtual ~Animal()
  {
    cout << "animal Destructor" << endl;
  }
};

class Cat : public Animal
{
public: 
  Cat()
  {
    cout << "cat Constructor" << endl;
  }
  ~Cat()
  {
    cout << "cat Destructor" << endl;
  }
};

int main() {
  Animal * polyCat = new Cat();
  delete polyCat;
}
