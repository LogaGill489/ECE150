#include <iostream>
int x = 1, y = 2, z = 3, a;
int main();

int main() {
    a = x;
    x = z;
    z = y;
    y = a;
    std::cout << x << y << z;
}

//1 + 2 + 16 + 64 + 128 + 512 + 16384 + 32768 = 
/*
1100001011010011
0100001010100111
----------------


*/