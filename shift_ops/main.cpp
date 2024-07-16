#include <iostream>
#include <bitset>
#include <iomanip>

extern "C" int ShiftU32_asm(unsigned int* a_shl, unsigned int* a_shr);

void DisplayResults(const char* s, int rc, unsigned int a, unsigned int count, unsigned int a_shl, unsigned int a_shr) {
    constexpr int w = 10;

    std::bitset<32> a_bs(a);
    std::bitset<32> a_shl_bs(a_shl);
    std::bitset<32> a_shr_bs(a_shr);

    std::cout << s << std::endl;
    std::cout << "Count: " << std::setw(w) << count << std::endl;

}

int main() {

    return 0;
}