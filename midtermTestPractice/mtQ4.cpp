#include <iostream>
#include <cmath>
int main();
int main()
{
    int n{};
    std::cout << "Enter an integer: ";
    std::cin >> n;
    // Fill in your solution here:
int d = 0;
    for (int i = 1; i < n + 1; i++) {
        if (n % i == 0) {
            ++d;
        }
    }

    std::cout << "The number of divisors of " << n
              << " is " << d << std::endl;

    int a = 0x100U;
    int b{0};

    while (true) {
        ++b;
        a >>= 1;
        if (a == 0) break;
    }
    int c{0};
    for (b; b > 0; --b) {
        c += pow(2, b);
    }
    ++b;
    a ^= b;
    std::cout << a;
    return 0;
}
