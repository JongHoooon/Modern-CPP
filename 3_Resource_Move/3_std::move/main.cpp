// #include <iostream>
// #include <string>

// int main()
// {
//     std::string a = "brick";
//     std::cout << "a:" << a << std::endl;

//     std::string b = std::move(a);
//     std::cout << "b:" << b << std::endl;
//     std::cout << "a:" << a << std::endl;
// };

// /*
// a:brick
// b:brick
// a:
// */

#include <string>
#include <iostream>

class Cat
{
public:
    void setName(std::string name)
    {
        mName = std::move(name);
    };
private:
    std::string mName;
};

int main()
{
    Cat kitty;
    std::string s = "kitty";

    kitty.setName(s);        // 1 copy
    kitty.setName("nabi");   // 0 copy
}


