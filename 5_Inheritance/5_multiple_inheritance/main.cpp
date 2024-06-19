class Animal
{
public:
  virtual void speak();
  virtual ~Animal() = default;
private:
  double animalData;
};

class Lion : public Animal
{
public:
  void speak() override;
private:
  double lionData;
};

int main(void) { 
  Animal * polyAnimal = new Lion();
  delete polyAnimal;
}
