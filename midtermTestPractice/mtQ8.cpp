#include <iostream>
int main();
int main() {
    std::cout << "input a number between 0-9: ";
    int n;
    std::cin >> n;
    for (int a = n; a >= 0; a--) {
        for (int k = 0; k < a; k++) {
            std::cout << "_";
        }
        for (int k = 0; k < (2*(n-a) + 1); k++) {
            std::cout << a;
        }
        std::cout << std::endl;
    }
}