/*
Name: Quick Sort
Author: Gaurav Sharma
Date: 27-04-19 18:01
Description: A simple c++ program to sort an array using Quick sort algorithm.
*/
#include <iostream>
#include <conio.h>
#include <time.h>

#define NO_RUNS 100
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

int main()
{
    srand(time(0));
    int *compr_array = new int[NO_RUNS];

    cout << "\nquick sort: \n";
    for (int k = 0; k < NO_RUNS; k++)
    {
        cout << "\n\nRUN " << k + 1;
        int size = 5 + (rand() % (15 - (5) + 1));

        cout << "\n\nsize : " << size;
        int *arr = new int[size];

        cout << "\n\nInitial array : ";
        for (int i = 0; i < size; i++)
        {
            arr[i] = -100 + (rand() % (100 - (-100) + 1));
            cout << "  " << arr[i];
        }

        int *sortArr = mergeSort(arr, size);
        int no_comp = count;
        compr_array[k] = no_comp;

        cout << "\n\ntotal no of comparisons : " << no_comp;
        cout << "\n\nSorted array : \n";
        for (int i = 0; i < size; i++)
        {
            cout << "\n"
                 << sortArr[i];
        }
    }

    getch();
    return 0;
}