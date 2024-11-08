#include <iostream>
using namespace std;

int main() {
    int N{3};
    int *p_N{&N};

    N = 4;

    cout << N;
    delete p_N;
    p_N = nullptr;
}