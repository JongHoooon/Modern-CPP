#include<string>

class Person 
{ 
    public: 
        Person(std::string name, int age)
            :name(std::move(name)), age(age){};
    private:
        std::string name;
        int age;
};

int main()
{
    Person a("brick", 22);

    Person * ap = new Person("brick", 33);
}