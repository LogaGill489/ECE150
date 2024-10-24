#include <iostream>
int main();

int is_sub_array(int arr1[], int cap1, int arr2[], int cap2)
{
    for (int n = 0; n < cap1; n++)
    {
        for (int a = 0; a < cap2; a++)
        {
            if (arr1[n + a] != arr2[a])
            {
                break;
            }
            else if (a==cap2 - 1) {
                return n;
            }
        }
        if (cap1 - n < cap2) {
            return cap2;
        }
    }
}

int main()
{
    int a1[10] = {0, 1, 1, 1, 2, 3, 5, 4, 2, 2};
    int a2[3] = {5, 4, 2};
    std::cout << is_sub_array(a1, 10, a2, 3);
}