#include <iostream>
using namespace std;

int n;

int binSearch(int *arr, int s, int e, int n)
{
    int m = (s + e) / 2;
    if (s <= e)
    {
        if (arr[m] < n)
            binSearch(arr, m + 1, e, n);
        else if (arr[m] > n)
            binSearch(arr, s, m - 1, n);
        else
            return m;
    }
    else
        return -1;
}

int main()
{
    cout << "\nenter size : ";
    cin >> n;

    cout << "\nenter sorted data (increasing order) : ";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nEnter element to be searched : ";
    int el;
    cin >> el;

    int x = binSearch(arr, 0, n - 1, el);
    (x == -1) ? cout << "\nnot found" : cout << "\nfound at " << x << " position";

    return 0;
}