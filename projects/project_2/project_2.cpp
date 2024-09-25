#include <iostream>
#include <cassert>

void pattern(unsigned int n)
{
    unsigned int counter = 0;
    for (unsigned int i = 1 + (n * 2); i > 0; --i)
    {
        if (i >= n + 1)
        {
            for (unsigned int j = 0; j < counter; ++j)
            {
                std::cout << " ";
            }
            for (unsigned int j = i; j > counter; --j)
            {
                std::cout << "*";
            }
        }
        else
        {
            for (unsigned int j = 1 + (n * 2); j > counter + 1; --j)
            {
                std::cout << " ";
            }
            for (unsigned int j = 1 + (n * 2) + 2; j > (2 * i); --j)
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
        counter++;
    }
}

unsigned int log10(unsigned int n)
{
    assert(n != 0);

    unsigned int m;
    while (n >= 10)
    {
        m++;
        n /= 10;
    }
    return m;
}

unsigned int count(unsigned int n, unsigned int bit)
{
    assert(bit == 0 || bit == 1);

    unsigned int total = 0;
    for (unsigned int i = 0; i < 32; ++i)
    {
        if (bit == (n & 1))
            ++total;

        n >>= 1;

        if (n == 0)
            break;
    }
    return total;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1)
{
    assert(b0 >= 0 && b0 <= 3);
    assert(b1 >= 0 && b1 <= 3);

    if (b0 == b1)
        return n;
    // 1111 1111
    unsigned int byteMask = 0xFFU;
    unsigned int byte0 = (n >> (b0 * 8)) & byteMask;
    unsigned int byte1 = (n >> (b1 * 8)) & byteMask;

    n &= ~(byteMask << (b0 * 8));
    n &= ~(byteMask << (b1 * 8));

    n |= (byte0 << (b1 * 8));
    n |= (byte1 << (b0 * 8));

    return n;
}

int main()
{
    // pattern
    std::cout << "n = 1:" << std::endl;
    pattern(1);
    for (unsigned int n{2}; n <= 5; ++n)
    {
        std::cout << std::endl;
        std::cout << "n = " << n << ":" << std::endl;
        pattern(n);
    }

    // logging
    unsigned int inN;
    std::cout << "Input a Value to Be Inputted Into Log of Base 10: ";
    std::cin >> inN;
    unsigned int rtnl = log10(inN);
    std::cout << "10^" << rtnl << " <= " << inN << "." << std::endl;

    // #of 1s and 0s in bitform of an int
    unsigned int bitn;
    unsigned int inB;
    std::cout << "Enter a number to have it's 1s and 0s counted: ";
    std::cin >> bitn;

    std::cout << "Should it count 1s or 0s?: ";
    std::cin >> inB;

    unsigned int rtnc = count(bitn, inB);
    std::cout << "There is " << rtnc << " " << inB << "(s)!" << std::endl;

    // swap bytes
    unsigned int in, b0, b1;
    std::cout << "Input a number to have it's bytes swapped: ";
    std::cin >> in;

    std::cout << "Enter byte #1: ";
    std::cin >> b0;

    std::cout << "Enter byte #2: ";
    std::cin >> b1;

    unsigned int rtnb = swap_bytes(in, b0, b1);
    std::cout << "The swapped bytes give " << rtnb << "!";

    return 0;
}
