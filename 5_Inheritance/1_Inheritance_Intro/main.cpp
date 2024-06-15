#include <iostream>
using namespace std;

class Animal
{
public:
  void sleep() const 
  {
    cout << "I'm sleeping" << endl;
  }
};

class Human : public Animal
{
public:
  void driveCar() const
  {
    cout << "I'm driving" << endl;
  }
};


int main(void) {
  Human brick;
  brick.driveCar();
  brick.sleep();
  return 0;
}