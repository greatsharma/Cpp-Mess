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
    if (top >= 0)
        return array[top--];
    else
        return 0;
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

int main()
{

    cout << "\nEnter size of first stack: ";
    int sizeStackOne;
    cin >> sizeStackOne;

    cout << "\nEnter size of second stack: ";
    int sizeStackTwo;
    cin >> sizeStackTwo;

    int data;

    stack objectOne(sizeStackOne);

    cout << "\nEnter number in first stack: ";
    for (int i = 0; i < sizeStackOne; i++)
    {
        cin >> data;
        objectOne.push(data);
    }

    stack objectTwo(sizeStackTwo);

    cout << "\nEnter number in second stack: ";
    for (int i = 0; i < sizeStackTwo; i++)
    {
        cin >> data;
        objectTwo.push(data);
    }

    cout << "\nStack one: ";
    objectOne.show();
    cout << "\nStack two: ";
    objectTwo.show();

    cout << "\n=============================";

    int sizeStackThree;

    sizeStackOne > sizeStackTwo ? (sizeStackThree = sizeStackOne + 1) : (sizeStackThree = sizeStackTwo + 1);

    stack objectThree(sizeStackThree);

    int carry = 0;

    for (int i = (sizeStackThree - 1); i >= 1; i--)
    {
        int localVar = sum(objectOne.pop(), objectTwo.pop(), carry);
        objectThree.push(localVar % 10);
        carry = (localVar / 10);
    }
    objectThree.push(carry);
    cout << "\nFinal sum is: ";
    for (int i = 0; i < (sizeStackThree); i++)

        cout << " " << objectThree.pop();

    cout << endl;
    system("pause");
    return 0;
}