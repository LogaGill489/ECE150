#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;

    int *p_a{&a};

    *p_a = 10;

    cout << &a << "  " << &b << "  " << &c << "  " << a;
}