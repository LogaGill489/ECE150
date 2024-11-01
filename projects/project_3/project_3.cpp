#include <iostream>
#include <cassert>
int main();

double *geometric(double a, double ratio, std::size_t cap)
{
    double *array = new double[cap]; // declare dynamically allocated array
    for (int i = 0; i < cap; i++)
    {
        array[i] = a;
        for (int k = 0; k < i; k++)
        {
            array[i] *= ratio;
        }
    }
    double *p_a{&array[0]};
    return p_a;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)
{
    assert(cap0 + cap1 >= 1);
    double *array = new double[cap0 + cap1 - 1];

    for (int i = 0; i < (cap0 + cap1 - 1); i++)
    {
        array[i] = 0.0;
    }

    for (int i = 0; i < cap0; i++)
    {
        for (int j = 0; j < cap1; j++)
        {
            array[i + j] += array0[i] * array1[j];
        }
    }
    return array;
}

std::size_t shift_duplicates(int array[], std::size_t capacity)
{
    int flipped{0};
    int tot_flipped{0};
    std::size_t uniques{0};
    bool did_flip = false;
    for (int i = 0; i < (capacity - flipped); i++)
    {
        for (int j = i + 1; j < (capacity - flipped); j++)
        {
            if (array[i] == array[j])
            {
                int set = array[i];
                for (int k = j; k < (capacity - 1); k++)
                {
                    array[k] = array[k + 1];
                }
                array[capacity - 1] = set;
                flipped++;
                j--;
                did_flip = true;
            }
        }
        if (did_flip) {
            did_flip = false;
            tot_flipped++;
        }
    }

    uniques = capacity - flipped;

    // prints out the array back for testing
    /*
    for (int i = 0; i < 2; i++) {
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;

    int k = 0;
    */

    return uniques;
}

void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0)
{
    if (is_array)
    {
        for (int i = 0; i < capacity; i++) {
            ptr[i] = 0;
        }
        delete[] ptr;
    }
    else
    {
        *ptr = 0;
        delete ptr;
    }
    ptr = nullptr;
}

int main()
{
    int array[11] = {0, 13, 2, 33, 4, 44, 89, 5, 345, 7679, 13};
    int arr2[2] = {0, 0};
    int arr[1] = {2};
    int data[10]{ 5, 4, 2, 2, 2, 4, 5, 1, 4, 3 };
    std::cout << shift_duplicates(arr2, 2);
    return 0;
}