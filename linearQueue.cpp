#include <iostream>

using namespace std;

bool flag = false;

class linearQueue
{
  private:
	int *array;
	int size;
	int front, rear; // front=exit rear=entry

  public:
	linearQueue();
	void enQueue(int);
	int deQueue();
	int firstElement();
	int lastElement();
	bool isEmpty();
	bool isFull();
	int noOfElements();
	void clear();
};

linearQueue::linearQueue()
{
	cout << "\nEnter size of queue:";
	cin >> size;

	array = new int[size];

	front = rear = -1;
}

void linearQueue::enQueue(int data)
{
	if (isFull())
		cout << "\nOVER-FLOW";
	else if (isEmpty())
	{
		++front;
		array[++rear] = data;
	}
	else
	{
		array[++rear] = data;
	}
}

int linearQueue::deQueue()
{
	if (isEmpty())
		cout << "\nUNDER-FLOW";
	else if (front == rear)
	{
		flag = true;
		int localVariable = array[front];
		front = rear = -1;
		return localVariable;
	}
	else
	{
		flag = true;
		return array[front++];
	}
}

int linearQueue::firstElement()
{
	if (isEmpty())
		cout << "\nNo first element, Queue is empty";
	else
	{
		flag = true;
		return array[front];
	}
}

int linearQueue::lastElement()
{
	if (isEmpty())
		cout << "\nNo last element, Queue is empty";
	else
	{
		flag = true;
		return array[rear];
	}
	return -1;
}

bool linearQueue::isEmpty()
{
	return rear == (-1);
}

bool linearQueue::isFull()
{
	return rear == (size - 1);
}

int linearQueue::noOfElements()
{
	return (isEmpty() ? 0 : (rear - front + 1));
}

void linearQueue::clear()
{
	front = rear = -1;
}

int main(void)
{
	linearQueue object;

start:

	cout << "\n========MENU========";
	cout << "\n1.EnQueue";
	cout << "\n2.DeQueue";
	cout << "\n3.First Element";
	cout << "\n4.Last Element";
	cout << "\n5.Is Empty";
	cout << "\n6.Is Full";
	cout << "\n7.Number of elements";
	cout << "\n8.Clear";
	cout << "\nEnter your choice:";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		int data;
		cout << "\nEnter data to be pushed:";
		cin >> data;
		object.enQueue(data);
		break;
	}

	case 2:
	{
		int localVariable = object.deQueue();
		if (flag)
		{
			cout << localVariable << " is being popped out";
			flag = false;
		}
		break;
	}

	case 3:
	{
		int localVariable = object.firstElement();
		if (flag)
		{
			cout << localVariable << " is the first element";
			flag = false;
		}
		break;
	}

	case 4:
	{
		int localVariable = object.lastElement();
		if (flag)
		{
			cout << localVariable << " is the last element";
			flag = false;
		}
		break;
	}

	case 5:
	{
		if (object.isEmpty())
			cout << "\nqueue is empty";
		else
			cout << "\nqueue is not empty";
		break;
	}

	case 6:
	{
		if (object.isFull())
			cout << "\nqueue is full";
		else
			cout << "\nqueue is not full";
		break;
	}

	case 7:
	{
		cout << object.noOfElements() << " elements are present in the queue";
		break;
	}

	case 8:
	{
		object.clear();
		break;
	}

	default:
		cout << "\nInvalid option...";
	}

	cout << "\nWant to try more options(y/n):";
	char ch;
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
		goto start;
	cout << "\n\n\nProgram Ends...";
	getch();
	return 0;
}
