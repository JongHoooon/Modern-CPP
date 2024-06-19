#include <iostream>
#include <memory>
using namespace std;

class Cat
{
public: 
  Cat(): mAge{0}
  {
    cout << "cat constructor" << endl;
  };
  ~Cat()
  {
    cout << "cat destructor" << endl;
  };

private:
  int mAge;
};

void foo(Cat * ptr)
{ 
  unique_ptr<Cat> catPtr = make_unique<Cat>();
  unique_ptr<Cat> catPtr1 = std::move(catPtr);
};

int main(void)
{
  Cat * catPtr = new Cat();
  Cat * catPtr1 = catPtr;
  foo(catPtr);
  delete catPtr;
}
