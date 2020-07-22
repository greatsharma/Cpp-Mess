#include <iostream>

#define MAX_SIZE 1000

using namespace std;

int maximum(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void radixSort(int arr[], int n)
{
    int max_digits = maximum(arr, n);

    int units = 1;

    int *temp = new int[n];
    int rem_arr[10];

    while (max_digits > 0)
    {
        max_digits = max_digits / 10;

        for (int i = 0; i < 10; i++)
        {
            rem_arr[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int index = (arr[i] / units) % 10;
            rem_arr[index] += 1;
        }

        for (int i = 1; i < 10; i++)
        {
            rem_arr[i] += rem_arr[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int index = (arr[i] / units) % 10;
            temp[rem_arr[index] - 1] = arr[i];
            rem_arr[index] -= 1;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }

        units = units * 10;
    }
}

int main()
{

    int arr[MAX_SIZE], size;

    cout << "\nEnter size : ";
    cin >> size;

    cout << "\nEnter array : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    radixSort(arr, size);

    cout << "\nSorted array : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\n";

    cin.get();
    return 0;
}