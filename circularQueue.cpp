#include <iostream>

using namespace std;

bool flag = false;

class circularQueue
{
  private:
	int *array;
	int size;
	int front, rear; // front=exit rear=entry
	int elements;

  public:
	circularQueue();
	void enQueue(int);
	int deQueue();
	int firstelement();
	int lastelement();
	bool isEmpty();
	bool isFull();
	int noOfelements();
	void clear();
};

circularQueue::circularQueue()
{
	cout << "\nEnter size of queue:";
	cin >> size;

	array = new int[size];

	front = rear = -1;
	elements = 0;
}

void circularQueue::enQueue(int data)
{
	if (isFull())
		cout << "\nOVER-FLOW";
	else if (isEmpty())
	{
		++front;
		array[++rear] = data;
		++elements;
	}
	else
	{
		rear = (rear + 1) % size;
		array[rear] = data;
		++elements;
	}
}

int circularQueue::deQueue()
{
	if (isEmpty())
	{
		cout << "\nUNDER-FLOW";
		return -1;
	}
	else if (front == rear == 0)
	{
		flag = true;
		--elements;
		rear = -1;
		return array[front--];
	}
	else
	{
		if (front == (size - 1))
		{
			int var = array[front];
			front = 0;
			return var;
		}
		else
			return array[front++];
		flag = true;
		--elements;
	}
}

int circularQueue::firstelement()
{
	if (rear == (-1))
		cout << "\nNo first element, Queue is empty";
	else
	{
		flag = true;
		return array[front];
	}
}

int circularQueue::lastelement()
{
	if (rear == (-1))
		cout << "\nNo last element, Queue is empty";
	else
	{
		flag = true;
		return array[rear];
	}
}

bool circularQueue::isEmpty()
{
	return rear == (-1);
}

bool circularQueue::isFull()
{
	return ((rear == (size - 1) && front == 0) || ((rear + 1) == front));
}

int circularQueue::noOfelements()
{
	return elements;
}

void circularQueue::clear()
{
	front = rear = -1;
	elements = 0;
}

int main(void)
{
	circularQueue object;

start:

	cout << "\n========MENU========";
	cout << "\n1.EnQueue";
	cout << "\n2.DeQueue";
	cout << "\n3.First element";
	cout << "\n4.Last element";
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
		int localVariable = object.firstelement();
		if (flag)
		{
			cout << localVariable << " is the first element";
			flag = false;
		}
		break;
	}

	case 4:
	{
		int localVariable = object.lastelement();
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
		cout << object.noOfelements() << " elements are present in the queue";
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

	cout << "\n\nWant to try more options(y/n):";
	char ch;
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
		goto start;
	cout << "\n\n\nProgram Ends...";

	return 0;
}