using namespace std;
#include <iostream>

int a = 0;
int b = 1;
int k = 1;
main() {
    int tracker = 0;
    while (k < 20) {
        tracker++;
        k = a+b;
        cout << a << " " << b << " " << k << "\n";
        a = b;
        b = k;
    }
    cout << "Done in " << tracker << " cycles!";
}