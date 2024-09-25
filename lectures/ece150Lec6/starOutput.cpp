#include <iostream>
#include <string>
using namespace std;

string input;
char inputChar[3] = {'a', 'a', 'a'};
bool active[3] = {false, false, false};

#pragma region decoders
void lgOutput()
{
    for (int i{0}; i < 3; i++)
    {
        if (active[i])
            cout << "*";
        else
            cout << " ";
    }
    cout << " ";
}
void shOutput()
{
    if (active[0])
        cout << "*";
    else
        cout << " ";
    cout << " ";
    if (active[2])
        cout << "*";
    else
        cout << " ";
    cout << " ";
}
void setLine()
{
    for (int i{0}; i < 3; i++)
    {
        active[i] = 1;
    }
}

void ln1Decoder(char input)
{
    switch (input)
    {
    case '1':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    case '4':
        active[0] = 1;
        active[1] = 0;
        active[2] = 1;
        break;
    default:
        setLine();
    }
    lgOutput();
}
void ln2Decoder(char input)
{
    switch (input)
    {
    case '1':
        active[0] = 0;
        active[2] = 1;
        break;
    case '2':
        active[0] = 0;
        active[2] = 1;
        break;
    case '3':
        active[0] = 0;
        active[2] = 1;
        break;
    case '5':
        active[0] = 1;
        active[2] = 0;
        break;
    case '6':
        active[0] = 1;
        active[2] = 0;
        break;
    case '7':
        active[0] = 0;
        active[2] = 1;
        break;
    default:
        setLine();
        break;
    }
    shOutput();
}
void ln3Decoder(char input)
{
    switch (input)
    {
    case '0':
        active[0] = 1;
        active[1] = 0;
        active[2] = 1;
        break;
    case '1':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    case '7':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    default:
        setLine();
        break;
    }
    lgOutput();
}
void ln4Decoder(char input)
{
    switch (input)
    {
    case '1':
        active[0] = 0;
        active[2] = 1;
        break;
    case '2':
        active[0] = 1;
        active[2] = 0;
        break;
    case '3':
        active[0] = 0;
        active[2] = 1;
        break;
    case '4':
        active[0] = 0;
        active[2] = 1;
        break;
    case '5':
        active[0] = 0;
        active[2] = 1;
        break;
    case '7':
        active[0] = 0;
        active[2] = 1;
        break;
    case '9':
        active[0] = 0;
        active[2] = 1;
        break;
    default:
        setLine();
    }
    shOutput();
}
void ln5Decoder(char input)
{
    switch (input)
    {
    case '1':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    case '4':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    case '7':
        active[0] = 0;
        active[1] = 0;
        active[2] = 1;
        break;
    default:
        setLine();
    }
    lgOutput();
}
#pragma endregion

main()
{
    while (true)
    {
        cout << "Please Enter a 3-Digit Input: ";
        cin >> input;
        if (input == "stop") {
            return 0;
        }
        for (int i{0}; i < 3; i++)
        {
            inputChar[i] = input[i];
        }
        for (int j{0}; j < 5; j++)
        {
            for (int i{0}; i < 3; i++)
            {
                switch (j)
                {
                case 0:
                    ln1Decoder(inputChar[i]);
                    break;
                case 1:
                    ln2Decoder(inputChar[i]);
                    break;
                case 2:
                    ln3Decoder(inputChar[i]);
                    break;
                case 3:
                    ln4Decoder(inputChar[i]);
                    break;
                case 4:
                    ln5Decoder(inputChar[i]);
                    break;
                }
                if (i == 2)
                {
                    cout << endl;
                }
            }
        }
    }

    /*
    *** *** ***
    * * * * * *
    *** *** ***
    * * * * * *
    *** *** ***
    */
}