// #include "foo.h"

void foo();

int main()
{
    foo();
    return 0;
}

/*
링킹 에러   

Undefined symbols for architecture arm64:
  "foo()", referenced from:
      _main in main-80f16b.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/

// g++ main.cpp -o foo -Wall -Werror - object 파일 생성, 머신코드

// g++ main.cpp -S -Wall -Werror - assembly 파일 