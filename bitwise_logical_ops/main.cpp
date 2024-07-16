#include <iostream>

extern "C" unsigned int BitOpsU32_asm(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

unsigned int BitOpsU32_cpp(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    // Calculating ~(((a & b) | c) ^ d)
    unsigned int t1 = a & b;
    unsigned int t2 = t1 | c;
    unsigned int t3 = t2 ^ d;
    return ~t3;
}

void DisplayResults(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int r1, unsigned int r2) {
    std::cout << "Results: " << std::endl;
    std::cout << "a =  " << a << std::endl;
    std::cout << "b =  " << b << std::endl;
    std::cout << "c =  " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "r1 =  " << r1 << std::endl;
    std::cout << "r2 =  " << r2 << std::endl;
}

int main() {
    unsigned int a = 5;
    unsigned int b = 2;
    unsigned int c = 9;
    unsigned int d = 10;

    unsigned int r1 = BitOpsU32_cpp(a, b, c, d);
    unsigned int r2 = BitOpsU32_asm(a, b, c, d);

    DisplayResults(a, b, c, d, r1, r2);
    return 0;
}