#include <iostream>
#include <time.h>

#define SIZE 10010      // Size of array.
#define NEW_ELE_SIZE 10 // No of elements after which we have to resort.
#define UB 1000         // Upper bound.
#define LB -1000        // Lower bound.
#define RUNS 100

using namespace std;

// O(SIZE*SIZE)
void insertionSort(int *Arr, int end = SIZE, int start = 0)
{
    for (int i = start + 1; i < end; i++)
    {
        int x = Arr[i];
        for (int j = i - 1; j >= start; j--)
        {
            if (Arr[j] > x)
            {
                Arr[j + 1] = Arr[j];
                Arr[j] = x;
            }
            else
                break;
        }
    }
}

// O(SIZE-NEW_ELE_SIZE)
void busInsertion(int *Arr, int Bus[])
{
    int bus_size = NEW_ELE_SIZE;

    for (int i = SIZE - NEW_ELE_SIZE - 1; i >= 0 && bus_size >= 1; --i)
    {
        if (Arr[i] > Bus[bus_size - 1])
        {
            Arr[i + bus_size] = Arr[i];
        }
        else
        {
            Arr[i + 1] = Bus[bus_size - 1];
            --bus_size;
            Arr[i + 1 + bus_size] = Arr[i + 1];
            Arr[i + bus_size] = Arr[i];
        }
    }
}

// O(SIZE)
void bubbleSwap(int *Arr)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            int temp = Arr[i + 1];
            Arr[i + 1] = Arr[i];
            Arr[i] = temp;

            if (Arr[i - 1] > Arr[i])
                i -= 2;
        }
    }
}

void prettyPrint(int *Array, int size = SIZE)
{
    for (int i = 0; i < size; ++i)
    {
        cout << " " << Array[i];
        if (i % 20 == 0)
            cout << "\n";
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

int main(void)
{
    srand(time(0));

    int Array[SIZE];

    for (int i = 0; i < RUNS; i++)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            Array[i] = LB + (rand() % (UB - LB + 1));
        }

        insertionSort(Array, SIZE - NEW_ELE_SIZE); // Till here we are provided everything.

        insertionSort(Array, SIZE /* end */, SIZE - NEW_ELE_SIZE /* start */); // O(NEW_ELE_SIZE * NEW_ELE_SIZE)

        int Bus[NEW_ELE_SIZE]; // extra space of NEW_ELE_sIZE

        for (int i = SIZE - NEW_ELE_SIZE, j = 0; i < SIZE; ++i)
        {
            Bus[j++] = Array[i];
        }

        busInsertion(Array, Bus); // O()
        bubbleSwap(Array);

        if (!testOfCorrection(Array, SIZE))
        {
            cout << "\nUnable to sort";
            return -1;
        }
    }

    cout << "\nAll sorted";
    cin.get();
    return 0;
}
