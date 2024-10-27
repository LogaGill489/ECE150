#include <iostream>
int main();

int reverse(int n) {
    int a{0};
    bool nTrue = false;
    if (n < 0) {
        nTrue = true;
        n *= -1;
    }
    do {
        a *= 10;
        a += n % 10;
        n /= 10;
    } while (n > 0);
    if (nTrue) {
        a *= -1;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverse(n);
}