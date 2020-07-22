#include <iostream>
using namespace std;

class stack
{
    int f, r, size;
    int *arr;

  public:
    stack(int size) : f(-1), r(-1), size(size) { arr = new int[size]; }

    void push(int data)
    {
        if (r >= size - 1)
            cout << "\noverflow";
        else if (r == -1 && f == -1)
        {
            ++f;
            arr[++r] = data;
        }
        else
            arr[++r] = data;
    }

    int dequeue()
    {
        if (f == -1)
            return -1;
        else if (f == r)
        {
            int x = arr[f];
            f = r = -1;
            return x;
        }
        else
        {
            return arr[f++];
        }
    }

    int pop()
    {
        if (f == -1)
            return -1;
        else
        {
            stack s(r);
            while (f < r)
                s.push(arr[f++]);

            int x = arr[f];
            f = r = -1;

            while (s.f < s.r)
                arr[++r] = s.dequeue();

            arr[++r] = s.dequeue();
            ++f;
            return x;
        }
    }
};

int main()
{
    int size;
    cout << "\nEnter size of stack : ";
    cin >> size;

    stack stack_obj(size);

startLabel:
    cout << "\n==========MENU==========";
    cout << "\n1. Push";
    cout << "\n2. Pop";
    cout << "\nEnter your choice: ";
    int optionMenu;
    cin >> optionMenu;

    switch (optionMenu)
    {
    case 1:
        int data;
        cout << "\nEnter data to push : ";
        cin >> data;
        stack_obj.push(data);
        break;

    case 2:
        int var = stack_obj.pop();
        if (var != -1)
            cout << "\npoped data is : " << var;
        else
            cout << "\nunderflow";
        break;
    }

    cout << "\nwant to try again(y/n): ";
    char chChoice;
    cin >> chChoice;

    if (chChoice == 'y' || chChoice == 'Y')
        goto startLabel;
}