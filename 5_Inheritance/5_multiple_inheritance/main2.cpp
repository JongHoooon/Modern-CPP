#include <iostream>
using namespace std;

class Animal
{
public: 
  Animal()
  { 
    cout << "Animal constructor" << endl;
  }
  virtual void speak()
  {
    cout << "Animal" << endl;
  }
  virtual ~Animal()
  {
    cout << "Animal destructor" << endl;
  }
private:
  double animalData;
};

class Lion : virtual public Animal
{
public:
  Lion() 
  {
     cout << "Lion constructor" << endl;
  }
  virtual void speak()
  {
    cout << "Lion!" << endl;
  }  
  virtual ~Lion()
  {
    cout << "Lion destructor" << endl;
  }
private:
  double lionData;
};

class Tiger : virtual public Animal
{
public: 
  Tiger() 
  {
    cout << "Tiger constructor" << endl;
  }
  virtual void speak()
  {
    cout << "Tiger!" << endl;
  }  
  virtual ~Tiger()
  {
    cout << "Tiger destructor" << endl;
  }
private:
  double tigerData;
};

class Liger : public Tiger, public Lion
{
public:
  Liger()
  {
    cout << "Liger constructor" << endl;
  }
  void speak() override
  {
    cout << "Liger!" << endl;
  }  
  virtual ~Liger() 
  {
    cout << "Liger destructor" << endl;
  }
private:
  double tigerData;
};

int main(void) { 
  Liger* polyLiger = new Liger();  
  polyLiger -> speak();
  delete polyLiger;
  return 0;
}
