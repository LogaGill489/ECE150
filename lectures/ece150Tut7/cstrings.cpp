#include <iostream>
using namespace std;

// note from class
// rtn[var++] = 3;   this gives rtn[var] = 3 and also does var++ in one line

char *interlace(char *arr1, char *arr2)
{
    std::size_t i;
    char *rtn{new char[41]{}};
    for (int i{0}; i < 41; i += 2)
    {
        if (arr1[i / 2] == '\0')
            break;
        rtn[i] = arr1[i / 2];
    }
    for (int i{1}; i < 42; i += 2)
    {
        if (arr2[i / 2] == '\0')
            break;
        rtn[i] = arr2[i / 2];
    }
    return rtn;
}

int main()
{
    char str1[21]{"cat"};
    char str2[21]{"dogpark"};

    cout << interlace(str1, str2);
}