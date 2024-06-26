#include <iostream>

int main()
{
    int sa = 0;
    int sb = 1;

    std::cout << "&sa : " << (long)&sa << std::endl;
    std::cout << "&sb : " << (long)&sb << std::endl; 

    int * hap = new int;
    int * hbp = new int;

    std::cout << "&hap : " << (long)&hap << std::endl;
    std::cout << "&hbp : " << (long)&hbp << std::endl;

    std::cout << "&ha : " << (long)hap << std::endl;
    std::cout << "&hb : " << (long)hbp << std::endl;

    // Prefer Smart Pointer
    delete hap;
    delete hbp;
    
    return 0;
}

/*
&sa : 6127710200
&sb : 6127710196
&hap : 6127710184
&hbp : 6127710176
&ha : 4812988608
&hb : 4812988624
*/