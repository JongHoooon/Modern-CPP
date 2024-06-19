#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "animal" << std::endl;
	}
	virtual ~Animal() = default;
private:
	double animalData;
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "meow~" << std::endl;
	}
	void knead()
	{
		std::cout << "kkuk kkuk" << std::endl;
	}
private:
	double catData;
};

class Dog : public Animal
{
public:
	void speak() override
	{
		std::cout << "bark!" << std::endl;
	}
	void wagTail()
	{
		std::cout << "wagging" << std::endl;
	}
private:
	double dogData;
};

int main()
{
  cout << typeid(Animal).name() << endl;
  cout << typeid(Cat).name() << endl;
  cout << typeid(Dog).name() << endl;

	// // downcast (base * -> derived *)
  // Animal * animalPtr = new Dog();
  // // VERY DANGEROUS
  // Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
  // if(catPtr == nullptr) 
  // {
  //   cout << "This is not a cat object" << endl;
  //   return 0;
  // }
  // catPtr -> speak();
  // delete catPtr;
  // return 0;
}
