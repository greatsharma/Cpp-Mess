/*
Name: Count Sort
Author: Gaurav Sharma
Date: 26-04-19 17:19
Description: A simple c++ program to sort an array using count sort algorithm.
*/
#include <iostream>
#include <time.h>

#define SIZE 100000 // Size of array.
#define UB 30000    // Upper bound ( maximum value for element).
#define LB 1000     // Lower bound ( minimum value for element).

using namespace std;

struct statis
{
    int min;
    int max;
} s;

void ArrRange(int *Arr)
{
    s.min = Arr[0], s.max = Arr[0];

    for (int i = 1; i < SIZE; ++i)
    {
        if (Arr[i] < s.min)
        {
            s.min = Arr[i];
        }
        else if (Arr[i] > s.max)
        {
            s.max = Arr[i];
        }
    }
}

void countSort(int *Arr, int *SortArr)
{
    ArrRange(Arr);
    int range = s.max - s.min + 1;
    int *temp = new int[range];

    for (int i = 0; i < range; ++i)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        temp[Arr[i] - s.min] += 1; // frequency
    }

    for (int i = 1; i < range; ++i)
    {
        temp[i] += temp[i - 1]; // cummulative frequency
    }

    for (int i = SIZE - 1; i >= 0; --i)
    {
        SortArr[temp[Arr[i] - s.min] - 1] = Arr[i];
        temp[Arr[i] - s.min] -= 1;
    }

    delete[] temp;
    delete[] Arr;
}

bool testOfCorrection(int *Arr, int len)
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
    int *Array = new int[SIZE];
    int *SortedArray = new int[SIZE];

    // Fill array
    for (int i = 0; i < SIZE; ++i)
    {
        Array[i] = LB + (rand() % (UB - LB + 1));
    }

    countSort(Array, SortedArray);

    if (!testOfCorrection(SortedArray, SIZE))
    {
        cout << "\nUNABLE TO SORT!";
        cin.get();
        return -1;
    }

    cout << "\nSORTED:)";
    cin.get();
    return 0;
}
