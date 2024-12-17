#include <iostream>

unsigned int f(unsigned int n)
{
    unsigned int a{0};
    for (unsigned int b{1}; b != 0; b <<= 1)
    {
        if (n & b)
            ++a;
    }
    return a;
}

unsigned long sqrt(unsigned long n) {
    unsigned long c{1};
    while (n >= (c+1)*(c+1)) {
        c++;
    }
    return c;
}

unsigned int square_sum(unsigned int n) {
    unsigned int sqr{0};
    for (unsigned int k{0}; k <= n; k++) {
        for (unsigned int j{0}; j <= k; j++) {
            sqr += j*j;
        }
    }
    return sqr;
}

void rot_array(int arr[], int size) {
    int temp{arr[size - 1]};
    for (int k{size - 1}; k > 0; k--) {
        arr[k] = arr[k-1];
    }
    arr[0] = temp;
}

unsigned int mingle(unsigned short m, unsigned short n) {
    unsigned int merged{0}, strg{1};
    for (unsigned short k{0}; k < 16; k++) {
        merged += (n & strg) << k;
        strg <<= 1;
    }
    strg = 1;
        for (unsigned short k{1}; k < 17; k++) {
        merged += (m & strg) << k;
        strg <<= 1;
    }
    return merged;
}

int main()
{
    unsigned int test{0b10110101};
    std::cout << f(test) << std::endl;
    std::cout << sqrt(36) << std::endl;
    std::cout << square_sum(4) << std::endl;
    int arr[5] {1, 2, 3, 4};
    rot_array(arr, 4);
    unsigned short k1{0b1111111111111110}, k2{1};
    std::cout << mingle(k1, k2) << std::endl;
    std::cout << mingle(k2, k1) << std::endl;
}