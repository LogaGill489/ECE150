#include <iostream>
unsigned int in{0};
unsigned int ilog2(unsigned int n)
{
    unsigned int c{0};
    do {
    n >>= 1;
    if (n == 0)
    {
        return c;
    }
    c++;
    } while (n != 0);
}

int main()
{
    std::cout << "Input a value to be logged: ";
    std::cin >> in;
    std::cout << ilog2(in);
}