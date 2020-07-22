#include <iostream>
#include <stdlib.h>
#include <fstream>

#define NO_RUNS 100

using namespace std;

int bubbleSort(int *arr, int size)
{
	int no_comp = 0;
	int wall = size - 1;

	for (int i = wall; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			++no_comp;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return no_comp;
}

int main()
{
	fstream file;
	file.open("bubbleCompArray.txt", ios::out | ios::trunc);

	if (!file)
	{
		cout << "\nerror opening file!!!";
		exit(-1);
	}

	int *compr_array = new int[NO_RUNS];

	for (int k = 0; k < NO_RUNS; k++)
	{
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

		int no_comp = bubbleSort(arr, size);

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
