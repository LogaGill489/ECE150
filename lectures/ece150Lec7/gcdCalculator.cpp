#include <iostream>
#include <cmath>

using namespace std;

main()
{
    for (;true;)
    {
        int in1, in2, temp1, temp2;
        cout << "Please enter the first value: ";
        cin >> in1;
        if (in1 < 0)
            in1 *= -1;

        cout << "Please enter the second value: ";
        cin >> in2;
        if (in2 < 0)
            in2 *= -1;

        int rem = 1;
        if (in1 >= in2)
        {
            temp1 = in1;
            temp2 = in2;
        }
        else
        {
            temp2 = in1;
            temp1 = in2;
        }

        while (rem != 0)
        {
            rem = temp1 % temp2;
            temp1 = temp2;
            temp2 = rem;
        }
        cout << "The gcd is " << temp1 << "!" << endl;
    }
}