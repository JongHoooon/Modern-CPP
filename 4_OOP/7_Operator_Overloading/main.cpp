#include <iostream>
using namespace std;

struct complexNum
{
  double real;
  double imag;

  complexNum(double r, double i): real{r}, imag{i} {
    cout << "init!" << endl;
  };
  void print() const
  { 
    cout << real << " " << imag << "i" << endl;
  }
};

complexNum operator+(const complexNum& lhs, const complexNum& rhs) 
{
  complexNum c{lhs.real + rhs.real, lhs.imag + rhs.imag};
  return c;
}

int main(void)
{
  complexNum c1{1, 1};
  complexNum c2{1, 2};
  complexNum c{c1 + c2};
  c.print();
}
