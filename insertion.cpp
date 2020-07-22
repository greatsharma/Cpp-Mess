#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define NO_RUNS 100

using namespace std;

int insertionSort(int *arr, int size)
{
	int no_comp = 0;

	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];

		for (int j = i - 1; j >= 0; j--)
		{
			++no_comp;
			if (temp < arr[j])
			{
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return no_comp;
}

int main()
{

	fstream file;

	file.open("insertionCompArray.txt", ios::out | ios::trunc);

	if (!file)
	{
		cout << "\nerror opening file!!!";
		exit(-1);
	}

	srand(time(0));

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

		int no_comp = insertionSort(arr, size);

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
