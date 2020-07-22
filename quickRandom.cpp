/*
Name: Randomized Quick Sort
Author: Gaurav Sharma
Date: 29-04-19 15:34
Description: A simple c++ program to sort an array using quick sort algorithm with random pivoting.
*/
#include <iostream>
#include <conio.h>
#include <time.h>

#define LB_SIZE 100   // Minimum array size.
#define UB_SIZE 10000 // Maximum array size.
#define UB_ELE 1000   // Minimum array element value.
#define LB_ELE -1000  // Maximum array element value.
#define RUNS 100      // Total runs.

using namespace std;
int count = 0;

void circularShift(int *Arr, const int &start, const int &end)
{
    int temp = Arr[end];
    for (int i = end - 1; i >= start; --i)
    {
        Arr[i + 1] = Arr[i];
    }
    Arr[start] = temp;
}

int partition(int *Arr, const int &start, const int &end)
{
    int r = start + (rand() % (end - start + 1)); // random pivot
    {
        int temp = Arr[start];
        Arr[start] = Arr[r];
        Arr[r] = temp;
    }

    int piv = start; // select first element as pivot.
    int var = start + 1;
    for (int i = start; i < end; ++i)
    {
        ++count;
        if (Arr[piv] > Arr[var])
        {
            circularShift(Arr, piv++, var++);
        }
        else
            ++var;
    }
    return piv;
}

void quickSort(int *Arr, int start, int end)
{
    if (start < end)
    {
        int piv_pos = partition(Arr, start, end);
        quickSort(Arr, start, piv_pos - 1);
        quickSort(Arr, piv_pos + 1, end);
    }
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
        quickSort(Arr, 0, size - 1);
        if (!testOfCorrection(Arr, size))
        {
            cout << "\nunable to sort! ";
            getch();
            return -1;
        }

        if (count > (size * (size - 1) / 2))
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