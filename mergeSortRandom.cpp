#include <iostream>
#include <math.h>
#include <conio.h>
#include <time.h>

#define LB_SIZE 100   // Minimum array size.
#define UB_SIZE 10000 // Maximum array size.
#define UB_ELE 1000   // Minimum array element value.
#define LB_ELE -1000  // Maximum array element value.
#define RUNS 100      // Total runs.

using namespace std;
int count = 0;

int *copyArr(int Arr[], const int start, const int end)
{
    int *copyArr = new int[end - start + 1];
    for (int i = start, j = 0; i <= end; ++i, ++j)
    {
        copyArr[j] = Arr[i];
    }
    return copyArr;
}

int *merge(const int Arr1[], const int Arr2[], const int &size1, const int &size2)
{
    int p1 = 0, p2 = 0;
    int size3 = size1 + size2;
    int *Arr3 = new int[size3];

    int i = 0;
    for (; i < size3 && p1 != size1 && p2 != size2; ++i)
    {
        if (++count && Arr1[p1] < Arr2[p2])
        {
            Arr3[i] = Arr1[p1++];
        }
        else if (Arr1[p1] > Arr2[p2])
        {
            Arr3[i] = Arr2[p2++];
        }
        else
        {
            Arr3[i++] = Arr1[p1++];
            Arr3[i] = Arr2[p2++];
        }
    }

    while (p1 != size1)
    {
        Arr3[i++] = Arr1[p1++];
    }

    while (p2 != size2)
    {
        Arr3[i++] = Arr2[p2++];
    }

    return Arr3;
}

int *mergeSort(int *Arr, const int size)
{
    if (size > 1)
    {
        int *Arr1 = copyArr(Arr, 0, size / 2 - 1);
        int *Arr2 = copyArr(Arr, size / 2, size - 1);
        int *Arr3 = mergeSort(Arr1, size / 2);
        int *Arr4 = mergeSort(Arr2, size - size / 2);
        return merge(Arr3, Arr4, size / 2, size - size / 2);
    }
    else
        return Arr;
}

bool testOfCorrection(int *Arr, int &len)
{
    for (int i = 1; i < len; i++)
    {
        if (Arr[i] < Arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    srand(time(0));
    cout << "\nExecuting wait for a second: \n";
    for (int r = 0; r < RUNS; ++r)
    {
        int size = LB_SIZE + (rand() % (UB_SIZE - LB_SIZE + 1));

        int *Arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            Arr[i] = LB_ELE + (rand() % (UB_ELE - LB_ELE + 1));
        }

        count = 0;
        int *sortArr = mergeSort(Arr, size);
        if (!testOfCorrection(sortArr, size))
        {
            cout << "\nunable to sort! ";
            getch();
            return -1;
        }

        if (count > (size * ceil(log2(size)) - pow(2, ceil(log2(size))) + 1))
        {
            cout << "\nwrong no of comp " << count << " for size " << size;
            getch();
            return -1;
        }
    }

    cout << "\nAll sorted with correct comparisons:)";
    getch();
    return 0;
}