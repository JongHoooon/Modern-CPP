#include<iostream>
#include<string>
using namespace std;

class Cat
{ 
public: 
  Cat(string name, int age): mName{std::move(name)}, mAge{age} {}
  string name() const
  {
    return mName;
  }
  int age() const
  { 
    return mAge;
  }
  // void print() const
  // {
  //   cout << mName << " " << mAge << endl;
  // }
  void print(ostream& os) const
  {
    os << mName << " " << mAge << endl;
  }
private:
  string mName;
  int mAge;
};
bool operator==(const Cat& lhs, const Cat& rhs) 
{
  return lhs.age() == rhs.age() && lhs.name() == rhs.name();
}
bool operator<(const Cat& lhs, const Cat& rhs)
{
  if(lhs.age() < rhs.age()) 
  { 
    return true;
  }
  return false;
}
ostream& operator<<(ostream& os, const Cat& c)
{
  return os << c.name() << " " << c.age();
}

int main(void) 
{ 
  Cat kitty{"kitty", 1};
  Cat nabi{"nabi", 2};

  kitty.print(cout);
  nabi.print(cout);
  cout << kitty << endl;
  cout << nabi << endl;
  return 0;
}