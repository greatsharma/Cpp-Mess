#include <iostream>
#include <time.h>

#define SIZE 500
#define LB 0 // Lower bound
#define UB 3 // Upper bound

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getColorFreq(int *Arr, int start, int color)
{
    int colorCount = 0;

    for (int i = start; i < SIZE; ++i)
    {
        if (Arr[i] == color)
        {
            ++colorCount;
        }
    }

    return colorCount;
}

void prettyPrint(int *Array)
{
    for (int i = 0; i < SIZE; ++i)
    {
        cout << " " << Array[i];
        if (i % 50 == 0)
            cout << "\n";
    }
}

int main()
{
    srand(time(0));

    int Array[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        Array[i] = LB + (rand() % (UB - LB + 1));
    }

    cout << "\nbefore sort: \n";
    prettyPrint(Array);

    int colorCount = 0;
    int boundary_index = 0;

    // O(4*SIZE)
    for (int color = 1; color <= 3; color++)
    {
        colorCount = getColorFreq(Array, boundary_index, color);

        for (int i = SIZE - 1, j = boundary_index; i >= 0 && colorCount >= 1 && boundary_index < SIZE; --i)
        {
            if (Array[i] == color)
            {
                swap(Array[j], Array[i]);

                if (Array[j] == color)
                    ++i;

                --colorCount;
                ++j;
                boundary_index = j;
            }
        }
    }

    cout << "\nafter sort: \n";
    prettyPrint(Array);

    cin.get();
    return 0;
}