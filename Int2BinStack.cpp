#include <iostream>
using namespace std;

class stack
{
  private:
    int top;
    int size;
    int *arr;

  public:
    stack(int size) : size(size), top(-1) { arr = new int[size]; }
    void push(int data) { arr[++top] = data; }
    int pop() { return (top > -1) ? arr[top--] : -1; }
    ~stack() {}
};

int main()
{
    cout << "\nEnter integer : ";
    int num;
    cin >> num;

    if (num == 0)
        cout << num;
    return 0;

    stack s(num);
    while (num > 0)
    {
        s.push(num % 2);
        num /= 2;
    }

    cout << "\nbinar eq : ";
    while (true)
    {
        int x = s.pop();
        if (x == -1)
            break;
        else
            cout << " " << x;
    }

    return 0;
}