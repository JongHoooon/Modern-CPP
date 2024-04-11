#include "cat.h"

int main()
{
    Cat kitty;
    kitty.speak();

    return 0;
}

/*
g++ cat.cpp -c 02 -Wall -Werror
ar -rs libcat.a cat.o
g++ main.cpp -lcat      
g++ main.cpp -L. -lcat

https://www.die.net/
*/