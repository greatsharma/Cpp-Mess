#include <iostream>
#include <conio.h>
using namespace std;

void countSort(int arr[], int n, int base)
{
    int result[n], i, rangeArr[10] = {0};

    // Store frequency.
    for (i = 0; i < n; i++)
    {
        rangeArr[(arr[i] / base) % 10]++;
    }

    // Find the Cumulative frequency
    for (i = 1; i < 10; i++)
    {
        rangeArr[i] += rangeArr[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        result[rangeArr[(arr[i] / base) % 10] - 1] = arr[i];
        rangeArr[(arr[i] / base) % 10]--;
    }

    // Mutate the original array
    for (i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

void radixSort(int arr[], int n)
{
    int max_base = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_base)
            max_base = arr[i];
    }

    for (int base = 1; base < max_base; base *= 10)
    {
        countSort(arr, n, base);
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *array = new int[size];

    cout << "\n Enter elments : ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    radixSort(array, size);

    cout << "\n\nSorted array is: \t";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    getch();
    return 0;
}