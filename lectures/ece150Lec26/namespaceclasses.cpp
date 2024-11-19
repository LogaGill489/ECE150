/*
Array Merging
- doesn't work for some reason


*/
#include <iostream>
#include <cassert>
using namespace std;

class yippee
{
public:
    int strg{}, rea{};
};

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

std::size_t is_sorted(char *array[], std::size_t capacity) // 2.5
{
    for (int i{0}; i < capacity - 1; i++)
    {
        if (compare(array[i], array[i + 1]) == 1)
            return (i + 1);
    }
    return capacity;
}

void merge(double array[], std::size_t cap_1, std::size_t cap_2)
{
    // assert(is_sorted(array, cap_1) == cap_1);
    // assert(is_sorted(array + cap_1, cap_2) == cap_2);
    double tmp_array[cap_1 + cap_2]{};
    std::size_t k1{0};
    std::size_t k2{cap_1};
    std::size_t j{0};
    while ((k1 < cap_1) && (k2 < cap_1 + cap_2))
    {
        if (array[k1] <= array[k2])
        {
            tmp_array[j] = array[k1];
            ++k1;
        }
        else
        {
            tmp_array[j] = array[k2];
            ++k2;
        }
        ++j;
    }
}

void merge_sort(double array[], std::size_t capacity)
{
    if (capacity <= 1)
    {
        return;
    }
    else
    {
        std::size_t capacity_1{capacity / 2};
        std::size_t capacity_2{capacity – capacity_1};
        merge_sort(array, capacity_1);
        merge_sort(array + capacity_1, capacity_2);
        merge(array, capacity_1, capacity_2);
    }
}

int main()
{
    int a1[8]{4, 7, 9, 16, 21, 22, 27};
    int a2[11]{2, 3, 6, 11, 18, 24, 25, 29, 32, 35};

    ostream &bob( ostream &out );
}