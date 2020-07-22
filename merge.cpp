#include <iostream>
#include <stdlib.h>
#include <fstream>

#define NO_RUNS 100
int count = 0;

using namespace std;

int *mergeSortedArray(int *arr1, int *arr2, int s1, int s2)
{
	int *arr3 = new int[s1 + s2];
	int var1 = 0, var2 = 0;

	for (int i = 0; i < s1 + s2; i++)
	{
		count++;

		if (arr1[var1] > arr2[var2] && var1 != s1 && var2 != s2)
		{
			arr3[i] = arr2[var2++];
		}
		else if (++count && arr1[var1] <= arr2[var2] && var1 != s1 && var2 != s2)
		{
			arr3[i] = arr1[var1++];
		}

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

int main()
{
	fstream file;
	file.open("mergeCompArray.txt", ios::out | ios::trunc);
	if (!file)
	{
		cout << "\nerror opening file!!!";
		exit(-1);
	}

	int *compr_array = new int[NO_RUNS];
	for (int k = 0; k < NO_RUNS; k++)
	{
		count = 0;
		cout << "\n\nRUN " << k + 1;
		int size = 5 + (rand() % (15 - (5) + 1));

		cout << "\n\nsize : " << size;

		int *arr = new int[size];

		cout << "\n\nInitial array : ";
		for (int i = 0; i < size; i++)
		{
			arr[i] = -100 + (rand() % (100 - (-100) + 1));
			cout << "  " << arr[i];
		}
		int *sortedarr = mergeSort(arr, size);
		int no_comp = count;

		compr_array[k] = no_comp;

		file << size << "," << no_comp << "\n";

		cout << "\n\ntotal no of comparisons : " << no_comp;

		cout << "\n\nSorted array : \n";
		for (int i = 0; i < size; i++)
		{
			cout << "\n"
				 << sortedarr[i];
		}
	}

	file.close();
	cin.get();
	return 0;
}
