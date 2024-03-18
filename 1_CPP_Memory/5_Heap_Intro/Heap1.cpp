int main() 
{
    int * ip;       // stack 에 포인트 할당
    ip = new int;   // 힙 공간에 int 사이즈 만큼 할당, ip 주소가 가리키게감
    *ip = 100;      // ip가 가리키는 힙 공간에 100 할당
    delete ip;      // 힙에 할당된 공간 삭제

    return 0;
}

/*
힙을 사용해야하는 이유?
1. life cycle
stack은 쌓고 deallocation 하는 방식으로 동작, dealloacation 되면 사라지는 문제 / 포인터만 신경 써주면 됨

2. large size
stack은 한계가 있어서 포인터로 큰 메모리 차지하는 힙에 접근할 수 있도록

3. Dynamic(runtime)
stack frame은 컴파일 시간에 정해짐
*/