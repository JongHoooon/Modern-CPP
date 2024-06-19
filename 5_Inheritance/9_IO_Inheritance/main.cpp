#include <iostream>
#include <string>
using namespace std;

class Cat 
{ 
public:
  Cat(string name, int age) : mName{std::move(name)}, mAge{age} {};
  void print(std::ostream & os)
  { 
    os << mName << "," << mAge << '\n';
  }
  void setFromStream(istream &is) 
  {

  }
private:
  string mName;
  int mAge;
};

int main() 
{
  Cat kitty{"kitty", 3};
  Cat nabi{"nabi", 2};

  kitty.print(cout);
  kitty.print(cout);
  return 0;
}