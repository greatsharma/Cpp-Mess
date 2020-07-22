#include <iostream>
#include <windows.h>

using namespace std;

bool flag = false, flag2 = true;
int counter = 0;

class colorConsole
{
  private:
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

  public:
	void doColor(int);
};

void colorConsole::doColor(int colorCode)
{
	SetConsoleTextAttribute(color, colorCode);
}

class stack
{
  private:
	int size, top, *array;
	colorConsole coloring;

  public:
	stack(int);
	int topElement();
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
	void clear();
	void multipush(int k, int *);
	int *multipop(int k);
	int noOfElements();
};

stack::stack(int size)
{
	this->size = size;
	array = new int[size];
	top = -1;
}

void stack::push(int data)
{
	if (top < (size - 1))

		array[++top] = data;

	else
	{
		coloring.doColor(12);
		cout << "\nOverflow!";
	}
}

void stack::multipush(int k, int *data)
{
	for (int i = 0; i < k; i++)
	{
		push(data[i]);
	}
	return;
}

int stack::pop()
{
	if (top < (size) && top >= 0)
	{
		flag = true;
		return array[top--];
	}
	else
	{
		coloring.doColor(12);
		flag = false;
		flag2 = false;
		cout << "\nUnderflow";
		return -1;
	}
}

int *stack::multipop(int k)
{
	int *temp = new int[k];

	for (int i = 0; i < k; i++)
	{
		if (flag2)
		{
			temp[i] = pop();
			if (flag)
				++counter;
		}
		else
			break;
	}

	flag = true;
	return temp;
}

int stack::topElement()
{
	if (top >= 0)
	{
		flag = true;
		return array[top];
	}
	else
	{
		coloring.doColor(12);
		cout << "\nNo top element, stack is empty";
	}
}

bool stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

void stack::clear()
{
	top = -1;
}

bool stack::isFull()
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

int stack::noOfElements()
{
	return (top + 1);
}

int main()
{
	//system("Color 0A");

	colorConsole coloring;
	coloring.doColor(13);

	// coloring.doColor(13);
	int size;
	cout << "\nEnter the size of array:";
	coloring.doColor(10);
	cin >> size;

	stack object(size);
label:
	coloring.doColor(10);
	cout << "\n====MENU====";
	coloring.doColor(11);
	cout << "\n1.";
	coloring.doColor(14);
	cout << " Push";
	coloring.doColor(11);
	cout << "\n2.";
	coloring.doColor(14);
	cout << " Pop";
	coloring.doColor(11);
	cout << "\n3.";
	coloring.doColor(14);
	cout << " Is-Empty";
	coloring.doColor(11);
	cout << "\n4.";
	coloring.doColor(14);
	cout << " Is-Full";
	coloring.doColor(11);
	cout << "\n5.";
	coloring.doColor(14);
	cout << " Clear";
	coloring.doColor(11);
	cout << "\n6.";
	coloring.doColor(14);
	cout << " Top Element";
	coloring.doColor(11);
	cout << "\n7.";
	coloring.doColor(14);
	cout << " Multi-Push";
	coloring.doColor(11);
	cout << "\n8.";
	coloring.doColor(14);
	cout << " Multi-Pop";
	coloring.doColor(11);
	cout << "\n9.";
	coloring.doColor(14);
	cout << " Number Of Elements\n";
	coloring.doColor(13);
	cout << "\nEnter choice:";
	int choice;
	coloring.doColor(10);
	cin >> choice;

	int data;

	switch (choice)
	{
	case 1:
	{
		coloring.doColor(13);
		cout << "\nEnter data to push:";
		coloring.doColor(10);
		cin >> data;
		object.push(data);
	}
	break;

	case 2:
	{

		int variable = object.pop();
		coloring.doColor(14);
		if (flag)
			cout << variable << " is popped";
		flag = false;
	}
	break;

	case 3:
	{

		if (object.isEmpty())
		{
			coloring.doColor(12);
			cout << endl
				 << "is empty";
		}
		else
		{
			coloring.doColor(10);
			cout << endl
				 << "not empty";
		}
	}
	break;

	case 4:
	{

		if (object.isFull())
		{
			coloring.doColor(10);
			cout << endl
				 << "is full";
		}

		else
		{
			coloring.doColor(12);
			cout << endl
				 << "not full";
		}
	}
	break;

	case 5:
	{

		object.clear();
		coloring.doColor(3);
		cout << "\ncleared";
	}
	break;

	case 6:
	{

		int variable = object.topElement();
		coloring.doColor(3);

		if (flag)
			cout << "\n"
				 << variable << " is top element";
		flag = false;
	}
	break;

	case 7:
	{
		int count;
		coloring.doColor(13);
		cout << "\nEnter no of elements:";
		coloring.doColor(10);
		cin >> count;
		int *element = new int[count];
		colorConsole coloring;
		coloring.doColor(13);
		cout << "\nEnter data to push:";
		coloring.doColor(10);
		for (int i = 0; i < count; i++)
			cin >> element[i];

		object.multipush(count, element);
	}
	break;

	case 8:
	{
		int count;
		coloring.doColor(13);
		cout << "\nEnter no of element to be popped:";
		coloring.doColor(10);
		cin >> count;

		int *temp = new int[count];
		temp = object.multipop(count);
		coloring.doColor(12);
		cout << "\nonly " << counter << " elements can be popped\n";
		coloring.doColor(14);
		if (flag)
			for (int i = 0; i < counter; i++)
				cout << temp[i] << " is poped\n";

		flag = false;
		flag2 = true;
		counter = 0;
	}
	break;

	case 9:
	{
		coloring.doColor(13);
		cout << object.noOfElements() << " no of elements in the queue";
		break;
	}

	default:
		cout << "\nInvalid choice...";
	}
	coloring.doColor(11);
	char ch;
	cout << "\n\nWant to select more choices(y/n):";
	coloring.doColor(10);
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		goto label;

	coloring.doColor(15);

	return 0;
}
