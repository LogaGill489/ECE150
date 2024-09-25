using namespace std;
#include <iostream>
#include <cmath>

float a, b, c;
bool input()
{
    cout << "Please Input A: ";
    cin >> a;
    cout << "Please Input B: ";
    cin >> b;
    cout << "Please Input C: ";
    cin >> c;
    cout << "                  2" << endl;
    cout << "The equation is " << a << "x  + " << b << "x + " << c << endl;
    string entry;
    while (entry != "y" && entry != "n")
    {
        cout << "Confirm? [y/n]: ";
        cin >> entry;
        if (entry != "y" && entry != "n")
            cout << "Error, please enter \"y\" or \"n\" to continue." << endl;
    }
    if (entry == "y")
        return 1;
    else
        return 0;
}

main()
{
    while (true)
    {
        bool run = false;
        while (!run)
        {
            run = input();
        }
        float t = b * b - 4 * a * c;
        float x1 = (-b + sqrt(t)) / 2 * a;
        float x2 = (-b - sqrt(t)) / 2 * a;
        bool check = _isnan(x1);
        if (check)
            cout << "This quadratic equation has no solutions." << endl;
        else
            cout << "The x Values Are: " << x1 << " & " << x2 << endl;
    }
}