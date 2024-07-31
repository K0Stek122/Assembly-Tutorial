#include <iostream>
#include <bitset>
#include <iomanip>

extern "C" int ShiftU32_asm(unsigned int* a_shl, unsigned int* a_shr, unsigned int a, unsigned int count); //Ignore a_shl, and a_shr. It was a failed attempt at parsing assembly more directly into C++.
// Focus on var_shl, and var_shr instead.
extern "C" {
    extern uint32_t var_shl;
    extern uint32_t var_shr;
}


void DisplayResults(const char* s, int rc, unsigned int a, unsigned int count, unsigned int a_shl, unsigned int a_shr) {
    constexpr int w = 10;

    std::bitset<32> a_bs(a);
    std::bitset<32> a_shl_bs(a_shl);
    std::bitset<32> a_shr_bs(a_shr);

    std::cout << s << std::endl;
    std::cout << "Count: " << std::setw(w) << count << std::endl;
    std::cout << "a: " << std::setw(w) << a << " (0b" << a_bs << ")" << std::endl;

    if (rc == 1) {
        std::cout << "shl:    " << std::setw(w) << a_shl;
        std::cout << " (0b" << a_shl_bs << ")" << std::endl;
        std::cout << "shr:    " << std::setw(w) << a_shl;
        std::cout << " (0b" << a_shr_bs << ")" << std::endl; 
    }
    else {
        std::cout << "Invalid Shift Count" << std::endl;
    }

}

int main() {
    int rc;
    unsigned int a, count, a_shl, a_shr;

    a = 0x00800080;
    count = 4;
    rc = ShiftU32_asm(&a_shl, &a_shr, a, count);
    DisplayResults("Shift Test: ", rc, a, count, var_shl, var_shr);
    return 0;
}