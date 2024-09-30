#include <iostream>

void square(int &n)
{
    n *= n;
}
int main()
{
    while (1)
    {
        int input;
        std::cout << "Please input a number to be squared: ";
        std::cin >> input;
        square(input);
        std::cout << "Your result is: " << input << std::endl;
        if (input == 0)
            return 0;
        input = 0;
    }
}