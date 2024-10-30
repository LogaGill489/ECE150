#include <iostream>
#include <cassert>
int main();

double *geometric(double a, double ratio, std::size_t cap)
{
    double *array = new double [cap]; //declare dynamically allocated array
    for (int i = 0; i < cap; i++) {
        array[i] = a;
        for (int k = 0; k < i; k++) {
            array[i] *= ratio;
        }
    }
    double *p_a{&array[0]};
    return p_a;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)
{
    assert( cap0 + cap1 >= 1);
    double *array = new double [cap0 + cap1 - 1];

    for (int i = 0; i < (cap0 + cap1 - 1); i++) {
        array[i] = 0.0;
    }

    for (int i = 0; i < cap0; i++) {
        for (int j = 0; j < cap1; j++) {
            array[i + j] += array0[i]*array1[j];
        }
    }
    return array;
}

std::size_t shift_duplicates(int array[], std::size_t capacity)
{
    return capacity;
}

void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0)
{
}

int main()
{

}