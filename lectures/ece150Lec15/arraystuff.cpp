#include <iostream>
using namespace std;

int arr[1]{};  // 4 bytes
int arr2[2]{}; // 8 bytes
int arr3[3]{}; // 12 bytes

int main()
{
    cout << arr << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;
}