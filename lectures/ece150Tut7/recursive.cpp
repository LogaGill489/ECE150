#include <iostream>
using namespace std;

void rec_print(char *str) {
    if (str[0] == '\0') {
        cout << endl;
    }
    else {
        rec_print(str + 1);
                cout << str[0];
    }
}

int main() {
    char str[21] {"Race fast safe car"};
    rec_print(str);
}