#include <iostream>
using namespace std;

class stack
{
	int size, *array, top;

  public:
	stack(int);
	void push(int);
	int pop();
	void show();
};

stack::stack(int size)
{
	this->size = size;
	array = new int[size];
	top = -1;
}

void stack::push(int data)
{
	array[++top] = data;
}

int stack::pop()
{
	return array[top--];
}

void stack::show()
{
	cout << endl;
	for (int i = 0; i < (this->size); i++)
		cout << array[i] << " ";
}

int sum(int varOne, int varTwo, int carry)
{

	return (varOne + varTwo + carry);
}

int subtract(int varOne, int varTwo)
{
	return (varOne - varTwo);
}

int main()
{

	cout << "\nEnter size of first stack: ";
	int sizeStackOne;
	cin >> sizeStackOne;

	cout << "\nEnter size of second stack: ";
	int sizeStackTwo;
	cin >> sizeStackTwo;

	int stackSize;
	int set;

	if (sizeStackOne == sizeStackTwo)
	{
		stackSize = sizeStackOne;
		set = 0;
	}
	else if (sizeStackOne > sizeStackTwo)
	{
		stackSize = sizeStackOne;
		set = sizeStackTwo;
	}
	else
	{
		stackSize = sizeStackTwo;
		set = sizeStackOne;
	}

	int data;

	stack objectOne(stackSize);

	cout << "\nEnter number in first stack: ";
	for (int i = 0; i < stackSize; i++)
	{
		cin >> data;
		objectOne.push(data);
	}

	stack objectTwo(stackSize);

	cout << "\nEnter number in second stack: ";
	for (int i = 0; i < stackSize; i++)
	{

		if (i < (stackSize - set) && (set != 0 || sizeStackOne == 0 || sizeStackTwo == 0))
			objectTwo.push(0);
		else
		{
			cin >> data;
			objectTwo.push(data);
		}
	}

	bool flagNeg = false;

	{
		int localVarOne = objectOne.pop();
		int localVarTwo = objectTwo.pop();
		if (localVarOne < 0 || localVarTwo < 0)
		{
			flagNeg = true;
		}

		objectOne.push(localVarOne);
		objectTwo.push(localVarTwo);
	}

	cout << "\nStack one: ";
	objectOne.show();
	cout << "\nStack two: ";
	objectTwo.show();

	cout << "\n=============================";

	stack objectThree(stackSize + 1);

	int carry = 0;

	for (int i = (stackSize - 1); i >= 0; i--)
	{
		int localVar = sum(objectOne.pop(), objectTwo.pop(), carry);
		objectThree.push(localVar % 10);
		carry = (localVar / 10);
	}
	objectThree.push(carry);
	cout << "\nFinal sum is: ";
	for (int i = 0; i < (stackSize + 1); i++)

		cout << " " << objectThree.pop();

	cout << endl;
	system("pause");
	return 0;
}
