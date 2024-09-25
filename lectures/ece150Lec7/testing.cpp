#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

main()
{
    float r;

    while (1)
    {
        cout << "Enter a Radius: ";
        cin >> r;

        float a = pow(r, 2) * M_PI;
        float d = 2 * r;
        float c = 2 * M_PI * r;
        float v = (4 / 3.0) * M_PI * pow(r, 3);

        cout << "Diameter: " << d << "m." << endl;
        cout << "Area: " << a << "m^2." << endl;
        cout << "Volume: " << v << "m^3." << endl;
        cout << "Circumference: " << c << "m." << endl << endl;
    }
}