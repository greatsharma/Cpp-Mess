#include <iostream>
#include <conio.h>

using namespace std;

// This generates one of the possible subsets.
void getSubset(bool **table, int *set, const int row_size, const int col_size)
{
    int *Arr = new int[row_size];
    int count = 0;
    int j = col_size;

    for (int i = row_size; i >= 1 && j >= 0; --i)
    {
        if (set[i - 1] <= j && table[i][j])
        {
            Arr[count] = set[i - 1];
            j -= set[i - 1];
            ++count;
        }
    }

    cout << "\n\nsubset with " << count << " elements: { ";
    for (int t = 0; t < count; ++t)
    {
        cout << Arr[t] << ", ";
    }
    cout << "}";
}

// This displays the DP Table.
void displayTable(bool **table, const int row_size, const int col_size)
{
    cout << "\nDP TABLE row->elements, col->sum: ";
    for (int i = 0; i < row_size; ++i)
    {
        cout << "\n";
        for (int j = 0; j < col_size; ++j)
        {
            cout << " " << table[i][j];
        }
    }
}

// Calculates DP Table.
bool subsetSum(int *set, const int size, const int sum)
{
    bool **table = new bool *[size + 1];
    for (int i = 0; i <= size; ++i)
    {
        table[i] = new bool[sum + 1];
    }

    for (int j = 1; j <= sum; ++j)
    {
        table[0][j] = false;
    }

    for (int i = 0; i <= size; ++i)
    {
        table[i][0] = true;
    }

    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            table[i][j] = table[i - 1][j];

            if (!table[i][j] && j >= set[i - 1])
            {
                table[i][j] = table[i - 1][j - set[i - 1]];
            }
        }
    }

    displayTable(table, size + 1, sum + 1);

    if (table[size][sum])
    {
        getSubset(table, set, size, sum);
    }

    return table[size][sum];
}

int main()
{
    cout << "\nEnter set size: ";
    int size;
    cin >> size;

    int *set = new int[size];
    cout << "\nEnter set elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> set[i];
    }

    cout << "\nEnter sum: ";
    int sum;
    cin >> sum;

    if (subsetSum(set, size, sum))
    {
        cout << "\n\nSubset exists:)";
    }
    else
    {
        cout << "\n\nNo subset exists!";
    }

    getch();
    return 0;
}
