#include <iostream>
#include <cassert>
using namespace std;
int bitflipper(int input, int a, int b) {
    assert(a >= 0 && a <=32);
    assert(b >= 0 && b <= 32);

    int c1 = (input >> a) & 1;
    int c2 = (input >> b) & 1;

    input &= ~(1 << a);
    input &= ~(1 << b);

    input |= (c1 << b);
    input |= (c2 << a);

    return input;
}
main() {
    int swapped, in1, in2;
    cin >> swapped;
    cin >> in1;
    cin >> in2;
    cout << bitflipper(swapped, in1, in2);
}