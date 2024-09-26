#include <iostream>
#include <cassert>
using namespace std;

main() {
    int input;
    int exponent;
    cout << "Enter a number greater than 1: ";
    cin >> input;

    assert(input > 1);
    while ((input & 1) == 0) {
        input >>= 1;
        exponent++;
    }
    cout << exponent;
}