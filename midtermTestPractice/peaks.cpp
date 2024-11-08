#include <iostream>
using namespace std;

void peaks(int n) {
    for (int i = 0; i < n; ++i) {
        for (int k = 1; k <= n; ++k) {
            for (int j = 1; j < k; ++j) {
                cout << " ";
            }
            cout << "\\" << endl;
        }

        for (int k = n; k > 0; --k) {
            for (int j = 1; j < k; j++) {
                cout << " ";
            }
            cout << "/" << endl;
        }
    }
}

int main() {
    while (true) {
        int in;
        cin >> in;
        peaks(in);
    }
}