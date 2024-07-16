#include <iostream>

/*
First, compile .asm with nasm nasm -f win32 --prefix _ -o int_arithmetic.o
Then, link with this cpp:
g++ -m32 int_arithmetic.o int_arithmetic.cpp -o int_arithmetic.exe
*/

extern "C" int AddSubI32_a(int a, int b, int c, int d);

void DisplayResults(int a, int b, int c, int d, int r1, int r2) {
    std::cout << "Results: " << std::endl;
    std::cout << "a =  " << a << std::endl;
    std::cout << "b =  " << b << std::endl;
    std::cout << "c =  " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "r1 =  " << r1 << std::endl;
    std::cout << "r2 =  " << r2 << std::endl;
}

int main() {
    int a = 15;
    int b = 16;
    int c = 9;
    int d = 6;
    int r1 = (a + b) - (c + d) + 7;
    int r2 = AddSubI32_a(a, b, c, d);

    DisplayResults(a, b, c, d, r1, r2);
    return 0;
}