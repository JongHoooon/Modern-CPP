#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Cat
{
public: 
  Cat(int age): mAge{age}
  {
    cout << "cat constructor" << endl;
  };
  ~Cat()
  {
    cout << "cat destructor" << endl;
  }

private:
  int mAge;
};

int main(void)
{
  // Cat kitty{1};

  // Cat * catPtr = new Cat{3};
  // delete catPtr;

  // unique_ptr<Cat> catPtr = make_unique<Cat>(3); // delete 처리하지 않아도 destructor 호출

  cout << "before scope" << endl;
  { 
    unique_ptr<Cat> catPtr = make_unique<Cat>(3);
  }
  cout << "after scope" << endl;
  return 0;
}

// void foo()
// { 
//   cout << "foo function" << endl;
//   Cat * cats = new Cat[5];
//   cout << "foo function end" << endl;
//   delete [] cate;
// }

void foo()
{ 
  cout << "foo function" << endl;
  vector<Cat> cats(5);
  cout << "foo function end" << endl;
}
