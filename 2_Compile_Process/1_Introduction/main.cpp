#include <iostream>
#include <variant>

int main() 
{
    // int i; // 기본 값을 주지 않아 문제가 생길 수 있음
    std::variant<int, float> i=0; // C== 17
    std::cout  << "hi" << std::endl;
    return 0;
}









// g++ main.cpp -o greeting - 파일 이름 설정
// g++ main.cpp -o greeting -Wall - 실행 과정중 생길 수 있는 error 를 compile 시간에 warning으로 나타내줌
// g++ main.cpp -o greeting -Wall -Werror - Warning을 Error로 변환
// g++ main.cpp -o greeting -Wall -std=c++17 - c++ 버전 명시
// g++ main.cpp -o greeting -Wall -std=c++17 -g - 디버그 인포메이션 확인
// g++ main.cpp -o greeting -Wall -std=c++17 -g -v - 컴파일레이션 과정 자세히
// g++ main.cpp -o greeting -Wall -std=c++17 -O0  - optimiazation 설정(gcc optimization level 참고)
// g++ main.cpp -o greeting -Wall -std=c++17 -O2 -march=native - optimization(gcc march 참고)