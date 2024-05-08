#include <string>

void storeByValue(std::string s)
{
    std::string b = s;
};

void storeByLRef(std::string & s)
{
    std::string b = s;
};

void storeByRRef(std::string && s)
{
    std::string b = std::move(s);
};

int main()
{
    std::string a = "abd";
    storeByValue(a);
    storeByLRef(a);
    storeByRRef("abd");
}
