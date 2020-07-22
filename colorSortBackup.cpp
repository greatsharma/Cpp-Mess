#include <iostream>
#include <time.h>

#define SIZE 20
#define LB 0 // Lower bound
#define UB 3 // Upper bound

#define RED 1
#define WHITE 2
#define BLUE 3

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void prettyPrint(int *Array)
{
    for (int i = 0; i < SIZE; ++i)
    {
        cout << " " << Array[i];
        if (i % 10 == 0)
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

    int count = 0;
    int boundary_index = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        if (Array[i] == RED)
        {
            ++count;
        }
    }

    cout << "\nred count: " << count;

    for (int i = SIZE - 1, j = boundary_index; i >= 0 && count >= 1; --i)
    {
        cout << "\ni: " << i;

        if (Array[i] == RED)
        {
            cout << "if";
            int temp = Array[j];
            Array[j] = Array[i];
            Array[i] = temp;

            if (temp == RED)
            {
                ++i;
            }

            --count;
            ++j;
            boundary_index = j;

            cout << "\n";
            prettyPrint(Array);
        }

        cout << "\ncount: " << count << " j: " << j << " boundary_index: " << boundary_index;
    }

    cout << "\nafter red sort: \n";
    prettyPrint(Array);

    count = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        if (Array[i] == WHITE)
        {
            ++count;
        }
    }

    cout << "\nwhite count: " << count;

    for (int i = SIZE - 1, j = boundary_index; i >= 0 && count >= 1; --i)
    {
        cout << "\ni: " << i;

        if (Array[i] == WHITE)
        {
            cout << "if";
            int temp = Array[j];
            Array[j] = Array[i];
            Array[i] = temp;

            if (temp == WHITE)
            {
                ++i;
            }

            --count;
            ++j;
            boundary_index = j;

            prettyPrint(Array);
        }

        cout << "\ncount: " << count << " j: " << j << " boundary_index: " << boundary_index;
    }

    cout << "\nafter white sort: \n";
    prettyPrint(Array);

    count = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        if (Array[i] == BLUE)
        {
            ++count;
        }
    }

    cout << "\nblue count: " << count;

    for (int i = SIZE - 1, j = boundary_index; i >= 0 && count >= 1; --i)
    {
        cout << "\ni: " << i;

        if (Array[i] == BLUE)
        {
            cout << "if";
            int temp = Array[j];
            Array[j] = Array[i];
            Array[i] = temp;

            if (temp == BLUE)
            {
                ++i;
            }

            --count;
            ++j;
            boundary_index = j;

            prettyPrint(Array);
        }

        cout << "\ncount: " << count << " j: " << j << " boundary_index: " << boundary_index;
    }

    cout << "\nafter blue sort: \n";
    prettyPrint(Array);

    cin.get();
    return 0;
}