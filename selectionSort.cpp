#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

#define NO_RUNS 100

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int size, int *arr)
{
	int count = 0;
	
    for (int i = 0; i < size; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
			count++;
			
			if (arr[j] < arr[small])
                small = j;
        }
        
		swap(&arr[i], &arr[small]);
    }
    
    return count;
}

int main()
{

	fstream file;
	
	file.open("selectionCompArray.txt",ios::out|ios::trunc);
	
	if(!file) 
	{
	 cout<<"\nerror opening file!!!";
	 exit(-1);
	}
	
	srand(time(0));
	
	for(int k=0;k<NO_RUNS;k++)
	{
	cout<<"\n\nRUN "<<k+1;
	int size =30 + ( rand() % (1000  - (30) + 1 ) );
	
	cout<<"\n\nsize : "<<size;
	
	int *arr = new int[size];
	
	cout<<"\n\nInitial array : ";
	for(int i=0;i<size;i++) 
	{
	 	arr[i] = -100 + ( rand() % ( 100 - (-100) + 1 ) );
		cout<<"  "<<arr[i];
	}
	
	int no_comp = selectionSort(size,arr);
	
	file<<size<<","<<no_comp<<"\n";
	
	cout<<"\n\ntotal no of comparisons : "<<no_comp;
	
	cout<<"\n\nSorted array : \n";
	for(int i=0;i<size;i++)
	{
		cout<<"\n"<<arr[i];
	}
}

	file.close();

	return 0;
}
