#include <iostream>
// class Cat
// {
// public:
//     void speak()
//     {
//         count++;
//         std::cout << count << "meow" << std::endl;
//     };
//     static int count;
//     static void staticSpeak()
//     {
//         std::cout << "CAT!" << std::endl;
//     };
// private:
//     int Age;
// };

class Cat
{
public:
    void speak()
    {
        static int count = 0;
        count++;
        std::cout << count << "meow" << std::endl;
    };
    static void staticSpeak()
    {
        std::cout << "CAT!" << std::endl;
    };
private:
    int Age;
};

int main()
{
    // Cat::staticSpeak();
    Cat kitty;
    Cat navi;
    kitty.speak();
    navi.speak();

    return 0;
}
