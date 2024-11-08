#include <iostream>
#include <cassert>
using namespace std;

unsigned int is_in( double x, double endpts[], int cap ) {
    assert(cap % 2 == 0);
    for (int a = 0; a < cap; a+=2){
        if (x > endpts[a] && x < endpts[a + 1]) {
            return (a/2) - 1;
        }
    }
    return (cap / 2);
}

int main() {
    while (true) {
    }
}