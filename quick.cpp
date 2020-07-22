#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

#define NO_RUNS 100
int count = 0;

using namespace std;

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
	{
		count++;
		if (arr[p0] > arr[p1])
			circularShift(arr, p0++, p1++);
		else
			++p1;
	}
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

int main()
{

	fstream file;

	file.open("quickCompArray.txt", ios::out | ios::trunc);

	if (!file)
	{
		cout << "\nerror opening file!!!";
		exit(-1);
	}

	int *compr_array = new int[NO_RUNS];
	srand(time(0));
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

		quickSort(arr, 0, size - 1);
		int no_comp = count;

		compr_array[k] = no_comp;

		file << size << "," << no_comp << "\n";

		cout << "\n\ntotal no of comparisons : " << no_comp;

		cout << "\n\nSorted array : \n";
		for (int i = 0; i < size; i++)
		{
			cout << "\n"
				 << arr[i];
		}
	}

	file.close();
	return 0;
}
