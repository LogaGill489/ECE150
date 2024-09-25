#include <iostream>
#include <string>
using namespace std;

string mirror (int n) {
    string sN = to_string(n);
    string temp;
    for (int i = sN.length() - 1; i > -1; --i) {
        temp += sN[i];
    }
    sN += " | " + temp;
    return sN;
}
main () {
    cout << "Enter a number: ";
    int in;
    cin >> in;
    cout << mirror(in);
}