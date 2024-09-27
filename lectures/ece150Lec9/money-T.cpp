#include <iostream>
#include <cassert>

int main()
{
    int input;
    std::cout << "Enter an odd number for the money T: ";
    std::cin >> input;
    assert(input % 2 != 0);
    assert(input >= 3);
    for (int i = 0; i < input; ++i)
    {
        std::cout << "$";
    }
    std::cout << std::endl;
    for (int i = 0; i < (input - 2); ++i)
    {
        for (int j = 0; j < ((input - 1) / 2); ++j)
        {
            std::cout << " ";
        }
        std::cout << "$" << std::endl;
    }
}