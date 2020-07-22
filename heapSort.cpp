// HEAP SORT WITH 1 INDEXING
#include <iostream>
#include <math.h>
#include <time.h>

#define SIZE 1000000 // Size of array.
#define UB 100000    // Upper bound ( maximum value for element).
#define LB -100000   // Lower bound ( minimum value for element).
#define RUNS 10      // Total of runs with different array.

int heap_size = 0;

using namespace std;

inline int Parent(int i)
{
    return floor(i / 2.0);
}

inline int Left(int i)
{
    return 2 * i;
}

inline int Right(int i)
{
    return 2 * i + 1;
}

inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *Arr, int i)
{
    int left = Left(i);
    int right = Right(i);
    int largest;

    if (left <= heap_size && Arr[left] > Arr[i])
        largest = left;
    else
        largest = i;

    if (right <= heap_size && Arr[right] > Arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(Arr[i], Arr[largest]);
        maxHeapify(Arr, largest);
    }
}

void buildMaxHeap(int *Arr)
{
    heap_size = SIZE;
    for (int i = floor(SIZE / 2.0); i >= 1; --i)
    {
        maxHeapify(Arr, i);
    }
}

void heapSort(int *Arr)
{
    buildMaxHeap(Arr);
    for (int i = SIZE; i >= 2; --i)
    {
        swap(Arr[1], Arr[i]);
        heap_size -= 1;
        maxHeapify(Arr, 1);
    }
}

bool testOfCorrection(int *Arr, int len)
{
    for (int i = 2; i <= len; i++)
    {
        if (Arr[i] < Arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    srand(time(0));
    int *Array = new int[SIZE + 1];

    for (int r = 0; r < RUNS; r++)
    {
        // Fill array
        for (int i = 1; i <= SIZE; ++i)
        {
            Array[i] = LB + (rand() % (UB - LB + 1));
        }

        heapSort(Array);

        if (!testOfCorrection(Array, SIZE))
        {
            cout << "\nUnable to sort";
            return -1;
        }
    }

    cout << "\nALL SORTED:)";
    cin.get();
    return 0;
}
