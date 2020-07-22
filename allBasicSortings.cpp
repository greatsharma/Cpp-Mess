#include <iostream>
#include <conio.h>
#include <time.h>

#define LB_SIZE 100
#define UB_SIZE 10000
#define UB_ELE 1000
#define LB_ELE -1000
#define RUNS 100

using namespace std;

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *Arr, const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
        {
            ++count;
            if (Arr[min] > Arr[j])
            {
                min = j;
            }
        }
        swap(&Arr[min], &Arr[i]);
    }
}

void bubbleSort(int *Arr, const int &size)
{
    for (int i = size - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++count;
            if (Arr[j] > Arr[j + 1])
            {
                swap(&Arr[j], &Arr[j + 1]);
            }
        }
    }
}

void insertionSort(int *Arr, const int &size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            ++count;
            if (Arr[j] > Arr[j + 1])
            {
                swap(&Arr[j], &Arr[j + 1]);
            }
            else
            {
                break;
            }
        }
    }
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
        // selectionSort(Arr, size);
        // bubbleSort(Arr, size);
        insertionSort(Arr, size);
        if (!testOfCorrection(Arr, size))
        {
            cout << "\nunable to sort!";
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