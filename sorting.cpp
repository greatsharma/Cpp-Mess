#include <iostream>
using namespace std;

//for swaping two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort
void selectionSort(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[small])
                small = j;
        swap(&arr[i], &arr[small]);
    }
}

//insertion sort
void insertionSort(int size, int *arr)
{
    for (int i = 1; i < size; i++)
    {
        int x = arr[i];
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] > x)
            {
                arr[j + 1] = arr[j];
                arr[j] = x;
            }
            else
                break;
    }
}

//bubble sort
void bubbleSort(int size, int *arr)
{
    int mark = size - 1;
    while (mark != 0)
    {
        for (int i = 0; i < mark; i++)
            if (arr[i + 1] < arr[i])
                swap(&arr[i], &arr[i + 1]);
        --mark;
    }
}

//3 merge sort functions
int *mergeSortedArray(int *arr1, int *arr2, int s1, int s2)
{
    int *arr3 = new int[s1 + s2];
    int var1 = 0, var2 = 0;

    for (int i = 0; i < s1 + s2; i++)
        if (arr1[var1] > arr2[var2] && var1 != s1 && var2 != s2)
            arr3[i] = arr2[var2++];
        else if (arr1[var1] <= arr2[var2] && var1 != s1 && var2 != s2)
            arr3[i] = arr1[var1++];
        else if (var1 != s1)
        {
            for (int j = i; j < s1 + s2; j++)
                arr3[j] = arr1[var1++];
            break;
        }
        else
        {
            for (int j = i; j < s1 + s2; j++)
                arr3[j] = arr2[var2++];
            break;
        }

    return arr3;
}

int *copyCat(int *arr, int start, int end)
{
    int *copyArr = new int[end - start + 1];
    for (int i = start, j = 0; i <= end; i++)
        copyArr[j++] = arr[i];

    return copyArr;
}

int *mergeSort(int *arr, int size)
{
    if (size == 1)
        return arr;
    else if (size > 1)
    {
        int *arr1 = copyCat(arr, 0, size / 2 - 1);
        int *arr2 = copyCat(arr, size / 2, size - 1);
        int *arr3 = mergeSort(arr1, size / 2);
        int *arr4 = mergeSort(arr2, size - size / 2);
        return mergeSortedArray(arr3, arr4, size / 2, size - size / 2);
    }
}

//3 quick sort functions
void circularShift(int *arr, int p0, int p1)
{
    int temp = arr[p1];
    for (int i = p1 - 1; i >= p0; i--)
        arr[i + 1] = arr[i];
    arr[p0] = temp;
}

int fixPivot(int *arr, int start, int end)
{
    int p0 = start, p1 = start + 1;
    for (int i = start; i < end; i++)
        if (arr[p0] > arr[p1])
            circularShift(arr, p0++, p1++);
        else
            ++p1;

    return p0;
}

void quickSort(int *arr, int start, int end)
{
    if (start == end || start > end || end < start)
        return;
    else
    {
        int pivPos = fixPivot(arr, start, end);
        quickSort(arr, start, pivPos - 1);
        quickSort(arr, pivPos + 1, end);
    }
}

//wave sort
void waveSort(int size, int *arr)
{
    bool flag = (arr[1] >= arr[0]) ? true : false;

    for (int i = 1; i < size; i++)
    {
        bool check = true;
        if (flag)
        {
            if (arr[i] < arr[i - 1])
            {
                for (int j = i + 1; j < size; j++)
                    if (arr[j] > arr[i - 1])
                    {
                        swap(&arr[i], &arr[j]);
                        check = false;
                        break;
                    }
                if (check)
                    swap(&arr[i], &arr[i - 1]);
            }
        }
        else
        {
            if (arr[i] > arr[i - 1])
            {
                for (int j = i + 1; j < size; j++)
                    if (arr[j] < arr[i - 1])
                    {
                        swap(&arr[i], &arr[j]);
                        check = false;
                        break;
                    }
                if (check)
                    swap(&arr[i], &arr[i - 1]);
            }
        }
        flag = !flag;
    }
}

//hill sort
int *hillSort(int *arr, int size)
{
    int *temp = new int[size];
    bool flag = true;

    for (int i = 0, j = 0, k = size - 1; i < size; i++)
    {
        cout << "\n\ni : " << i;
        if (flag)
        {
            temp[j] = arr[i];
            for (int m = j; m > 0 && j - 1 >= 0; m--)
                if (temp[m - 1] > temp[m])
                    swap(&temp[m - 1], &temp[m]);
            ++j;
        }
        else
        {
            temp[k] = arr[i];
            for (int m = k; m < size - 1 && k + 1 <= size - 1; m++)
                if (temp[m] < temp[m + 1])
                    swap(&temp[m], &temp[m + 1]);
            --k;
        }
        flag = !flag;
    }

    return temp;
}

//for displaying array
void display(int size, int *arr)
{
    cout << "\n";
    for (int i = 0; i < size; i++)
        cout << "  " << arr[i];
}

int main()
{
    cout << "\nenter size : ";
    int size;
    cin >> size;

    int *arr = new int[size];
    cout << "\nEnter array (waves never contains same value): ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\n1. selection\n2. insertion\n3. bubble\n4. merge\n5. quick\n6. wave\n7. hill\n\nEnter your choice : ";
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        selectionSort(size, arr);
        break;

    case 2:
        insertionSort(size, arr);
        break;

    case 3:
        bubbleSort(size, arr);
        break;

    case 4:
        arr = mergeSort(arr, size);
        break;

    case 5:
        quickSort(arr, 0, size - 1);
        break;

    case 6:
        waveSort(size, arr);
        break;

    case 7:
        arr = hillSort(arr, size);
        break;

    default:
        cout << "\ninvalid";
    }

    display(size, arr);
    return 0;
}