// static int a=100; // 오브젝트 파일, 트랜스레이트 유닛 외부로 링크를 주지 않는다는 확신이 있을때 사용!

/*
duplicate symbol '_a' in:
    /private/var/folders/nd/865yhs391bx0wb83bpbt429w0000gn/T/main-aa4408.o
    /private/var/folders/nd/865yhs391bx0wb83bpbt429w0000gn/T/foo-2b28ae.o
ld: 1 duplicate symbols
clang: error: linker command failed with exit code 1 (use -v to see invocation)

a 중복 선언돼서 컴파일은 됐지만 링크가 안됨 
*/ 

// #include <iostream>
// static void bar()
// {
//     std::cout << "bar" << std::endl;
// }

// void foo()
// {
//     std::cout << "foo" << std::endl;
// }
 
 #include "foo.h"
 
 int foo(double a)
 {
    return static_cast<int>(a);
 }
 double bar(int a)
 {
    return static_cast<double>(a);
 }
