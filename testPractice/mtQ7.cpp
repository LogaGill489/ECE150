#include <iostream>
#include <bitset>
int main();
int main() {
    int c{0}, n{0}; //c is a counter
    std::cin >> n;
    do {
        if (n >>= (2*c) & 1 == 0) {
            n |= (1 << ((2*c) + 1));
        }
        else {
            n^= (1 << ((2*c) + 1));
        }
        ++c;
    } while(c < 15);
    std::bitset<32> b(n);
    std::cout << b;
}