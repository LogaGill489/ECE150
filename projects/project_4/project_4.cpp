#include <iostream>
#include <fstream>
#include <cassert>
#include "p_4_header.hpp"

void print_array(char *array[], int capacity) // test array
{
    for (int i{0}; i < capacity; i++)
        std::cout << array[i] << std::endl;
    std::cout << std::endl;
}

std::size_t length(char const *a) // 2.1
{
    std::size_t count{0};
    while (a[count] != 0)
        count++;
    return count;
}
int compare(char const *str1, char const *str2) // 2.2
{
    // return -1 if 1 comes before 2, 0 if they are same, 1 if 2 comes before 1
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
    // std::size_t cap1{length(str1)};
    std::size_t cap2{length(str2)};

    for (int i{0}; i <= cap2; i++)
        str1[i] = str2[i];
}
unsigned int distance(char const *str1, char const *str2) // 2.4
{
    if (str1[0] == '\0')
        return length(str2);
    if (str2[0] == '\0')
        return length(str1);

    if (str1[0] == str2[0])
        return distance(str1 + 1, str2 + 1);

    unsigned int rtn;
    rtn = std::min(std::min(distance(str1 + 1, str2 + 1), distance(str1, str2 + 1)), distance(str1 + 1, str2));
    return ++rtn;
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
    for (int i{0}; i < capacity; i++)
    {
        if (compare(array[i], array[capacity - 1]) == 1)
        {
            char *temp = array[capacity - 1];
            for (int j = capacity - 1; j >= i; j--)
                array[j] = array[j - 1];
            array[i] = temp;
            break;
        }
    }
    // print_array(array, capacity);
}
void insertion_sort(char *array[], std::size_t capacity) // 2.7
{
    /*char *arr{new char[21 * capacity]};
    for (int i{0}; i < 21 * capacity; i++)
        arr[i] = (*array)[i];*/

    for (int i{2}; i <= capacity; i++)
        insert(array, i);

    /*for (int i{0}; i < 21 * capacity; i++)
        (*array)[i] = arr[i];*/
}
std::size_t remove_duplicates(char *array[], std::size_t capacity) // 2.8
{
    std::size_t removed{0};
    for (int i{0}; i < capacity - 1 - removed; i++)
    {
        for (int j{i + 1}; j < capacity - 1 - removed; j++)
        {
            if (compare(array[i], array[j]) == 0)
            {
                for (j; j <= capacity - removed - 1; j++)
                    array[j] = array[j + 1];
                array[capacity - removed - 1] = 0;
                removed++;
            }
        }
    }
    // print_array(array, capacity - removed);
    return capacity - removed;
}
std::size_t find(char *array[], std::size_t capacity, char const *str) // 2.9
{
    // check if they are equal
    /*
    for (int i{0}; i < capacity; i++) {
        if (compare(array[i], str) == 0)
            return i;
    }
    */
    // if they aren't equal
    std::size_t pos{0}, gap{distance(array[0], str)};
    for (int i{1}; i < capacity; i++)
    {
        if (distance(array[i], str) < gap)
        {
            pos = i;
            gap = distance(array[i], str);
        }
    }
    return pos;
}

void free_word_array(char **word_array) // 2.11
{
    delete[] word_array[0];
    delete[] word_array;
}

// main is used purely for my own testing of the functions made
/*int main()
{
    // test variables for functions
    char a1[21]{'a', 'w', 'o', 'a'};
    char a2[21]{'b', 'e', 'x', 'q', 'k', 'r', 'e', 'r', 'b', 'a', 'z', 'y', 'q', 'z', 'q', 'i', 't', 't', 't'};
    char a3[21]{'c', 'q', 'p', 'j', 't'};
    char a4[21]{'d', 'j', 'q', 'u', 'i', 'g', 'u'};
    char a5[21]{'e', 'v', 'j', 'y', 'e', 'r', 'h', 'j', 'n', 'p', 'm', 'o', 'n', 'p', 'm', 'g', 'r', 'p', 'n'};
    char a6[21]{'f', 'm', 'z', 'i', 'r', 'e', 'c', 't', 'e', 'u', 'q', 'i', 'x', 'z', 'y'};
    char a7[21]{'c', 'q', 'p', 'j', 't'};
    char a8[21]{'e', 'v', 'j', 'y', 'e', 'r', 'h', 'j', 'n', 'p', 'm', 'o', 'n', 'p', 'm', 'g', 'r', 'p', 'n'};
    char a9[21]{'e', 'p', 'j', 'e', 'i', 'e', 'n', 'u', 'm'};
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
    char *p_s2[21]{a3, a2, a7, a4, a1, a6, a5, a9, a8};

    std::cout << length(a1) << std::endl;      // 2.1
    std::cout << compare(a1, a2) << std::endl; // 2.2

    std::cout << std::endl; // 2.3
    // assign(a1, a2);

    // testing loop
    for (int i{0}; i < length(a2); i++)
    {
        std::cout << a1[i] << std::endl;
    }

    // std::cout << distance(a1, a2) << std::endl; // 2.4

    // std::cout << is_sorted(p_s1, 9) << std::endl; //2.5

    // insert(p_s1, 9); //2.6

    insertion_sort(p_s2, 9);
    for (int i{0}; i < 9; i++)
    {
        std::cout << p_s2[i] << std::endl;
    }

    // std::cout << remove_duplicates(p_s1, 9) << std::endl;
    return 1;
}*/
