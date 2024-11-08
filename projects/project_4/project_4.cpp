#include <iostream>
#include "p_4_header.hpp"
int main();

std::size_t length(char const *a) // 2.1
{
    std::size_t count{0};
    while (a[count] != 0)
    {
        count++;
    }
    return count;
}
int compare(char const *str1, char const *str2) // 2.2
{
    // return -1 if 1 comes before 2, 0 if they are same, 1 is 2 comes before 1
    std::size_t count{0};
    while (true)
    {
        if (str1[count] == str2[count])
        {
            if (str1[count] == 0)
                return 0;
        }
        else if (str1[count] < str2[count])
            return -1;
        else
            return 1;
        count++;
    }
}
void assign(char *str1, char const *str2) // 2.3
{
    // makes str1 into str2
    std::size_t cap1{length(str1)};
    std::size_t cap2{length(str2)};

    for (int i{0}; i < cap2; i++)
        str1[i] = str2[i];

    if (cap1 > cap2)
    {
        for (cap2; cap2 < cap1; cap2++)
            str1[cap2] = 0;
    }
}
unsigned int distance(char const *str1, char const *str2) // 2.4
{
    std::size_t cap1{length(str1)};
    std::size_t cap2{length(str2)};
    unsigned int dist{0};

    unsigned int fro{0};
    while (true)
    {
        if (str1[fro] == str2[fro])
        {
            fro++;
            if (str1[fro] == 0)
                return 0;
        }
        else
            break;
    }

    if (cap1 < cap2) // increase to size
    {
    }
    else // decrease to size
    {
        bool remove = false;
        // decide between deleting or changing
        for (int i = 1; i < std::min(cap1, cap2) - fro; i++)
        {
            if (str1[fro] == str2[fro + i])
            {
            }
        }
    }

    return dist;
}
std::size_t is_sorted(char *array[], std::size_t capacity) // 2.5
{
    for (int i{0}; i < capacity - 1; i++)
    {
        if (compare(array[i], array[i + 1]) == 1)
            return (i + 1);
    }
    return capacity;
}
void insert(char *array[], std::size_t capacity) // 2.6
{
}
void insertion_sort(char *array[], std::size_t capacity) // 2.7
{
}
std::size_t remove_duplicates(char *array[], std::size_t capacity) // 2.8
{
}
std::size_t find(char *array[], std::size_t capacity, char const *str) // 2.9
{
}
void read_words_from_file(char const *filename, char **&work_array, std::size_t &numwords, std::size_t max_length) // 2.10
{
}
void free_word_array(char **word_array) // 2.11
{
}

// main is used purely for my own testing of the functions made
int main()
{
    //test variables for functions
    char a1[21]{'a', 'w', 'o', 'a'};
    char a2[21]{'b', 'e', 'x', 'q', 'k', 'r', 'e', 'r', 'b', 'a', 'z', 'y', 'q', 'z', 'q', 'i', 't', 't', 't'};
    char a3[21]{'a', 'q', 'p', 'j', 't'};
    char a4[21]{'d', 'j', 'q', 'u', 'i', 'g', 'u'};
    char a5[21]{'e', 'v', 'j', 'y', 'e', 'r', 'h', 'j', 'n', 'p', 'm', 'o', 'n', 'p', 'm', 'g', 'r', 'p', 'n'};
    char a6[21]{'f', 'm', 'z', 'i', 'r', 'e', 'c', 't', 'e', 'u', 'q', 'i', 'x', 'z', 'y'};
    char a7[21]{'g', 'c', 'w'};
    char a8[21]{'h', 's', 'i'};
    char a9[21]{'i', 'p', 'j', 'e', 'i', 'e', 'n', 'u', 'm'};
    char a10[21]{'j', 'v', 'e', 'r', 'y', 'x', 'l', 'k'};
    char a11[21]{'k', 'n', 'q', 'r', 'd', 'e', 'n', 'h', 'p', 'l', 'n', 'l', 's'};
    char a12[21]{'l', 'q', 'r', 'e', 'j', 'r', 'f', 'k', 't', 'r', 'r', 'j', 'f', 'u'};
    char a13[21]{'l', 'r', 's', 'i', 'h', 'o', 'o', 'r', 'h', 'f', 'u'};
    char a14[21]{'y', 'c', 'o', 'a', 'h', 'g', 'x', 'c', 'm', 'h', 'q', 'r'};
    char a15[21]{'r', 'b', 'b', 'p', 'y', 'l', 'i', 'k', 'c', 'x', 'l', 'v', 'u', 'o', 'l', 't', 't', 'y'};
    char a16[21]{'n', 'y', 'b', 'h', 'z', 'n', 'a', 'b', 'j', 'p'};
    char a17[21]{'e', 'v', 'z', 'a', 'j', 'n', 'y', 'i', 'o'};
    char a18[21]{'p', 'i', 's', 'v', 'b', 'w', 'b', 'j', 'v', 'n', 'n', 'i', 'e', 'o', 'h', 'o', 'k', 'y'};
    char a19[21]{'q', 'h', 's', 'y', 'z', 'q', 'z', 'z'};
    char a20[21]{'o', 'k', 'l', 'r', 'l', 'm', 'c', 's'};

    std::string s1[21]{"alpha", "beta", "delta", "gamma", "sigma"};
    char *p_s1[21]{a1, a2, a3, a4, a5, a6, a7, a8, a9};

    std::cout << length(a1) << std::endl;      // 2.1
    std::cout << compare(a1, a2) << std::endl; // 2.2

    std::cout << std::endl; // 2.3
    assign(a1, a2);

    // testing loop
    for (int i{0}; i < length(a2); i++)
    {
        std::cout << a1[i] << std::endl;
    }

    // std::cout << distance(a1, a2) << std::endl; // 2.4

    std::cout << is_sorted(p_s1, 8) << std::endl;
    return 1;
}