#include <iostream>
using namespace std;

class Node
{
  private:
    int data;
    Node *next;
    Node *prev;
    friend class DLL;

  public:
    Node(int data, Node *prev, Node *next = 0) : data(data), next(next), prev(prev) {}
    ~Node() {}
};

class DLL
{
  private:
    static Node *head;
    static Node *tail;

  public:
    DLL() {}
    void insertAtTail(int);
    void reverse();
    void reverseIter(Node *curr = head);
    void showHeadTail() { cout << "  head : " << head << "    tail : " << tail; }
    int lengthDLL(Node *curr = head, int count = 0);
    void display();

    void displayReverse(Node *curr = tail)
    {
        if (curr)
        {
            cout << "  " << curr->data;
            displayReverse(curr->prev);
        }
    }

    ~DLL() {}
};

Node *DLL::head = 0;
Node *DLL::tail = 0;

void DLL::insertAtTail(int data)
{
    Node *node = new Node(data, tail);
    if (head)
    {
        tail->next = node;
        tail = node;
    }
    else
        head = tail = node;
}

void DLL::reverse()
{
    if (head)
    {
        Node *curr = head;
        Node *temp;

        while (curr)
        {
            temp = curr->next;
            if (curr != head)
                curr->next = head;
            else
            {
                curr->next = 0;
                tail = head;
            }
            curr->prev = temp;
            head = curr;
            curr = temp;
        }
    }
}

void DLL::reverseIter(Node *curr)
{
    if (curr)
    {
        Node *temp = curr->next;
        if (curr != head)
            curr->next = head;
        else
        {
            curr->next = 0;
            tail = head;
        }
        curr->prev = temp;
        head = curr;
        reverseIter(temp);
    }
}

int DLL::lengthDLL(Node *curr, int count)
{
    if (curr)
    {
        ++count;
        lengthDLL(curr->next, count);
    }
    else
        return count;
}

void DLL::display()
{
    if (head)
    {
        Node *curr = head;
        while (curr)
        {
            cout << "  " << curr->data;
            curr = curr->next;
        }
    }
}

int main()
{
    int data;
    char ch;

    DLL l;
    cout << "\nEnter DLL : ";
    do
    {
        cout << "\nEnter node data : ";
        cin >> data;
        l.insertAtTail(data);

        cout << "\nenter 0 to exit : ";
        cin >> ch;
    } while (ch != '0');

    cout << "\nl : ";
    l.display();
    l.showHeadTail();

    // l.reverseIter();
    // cout << "\nl it : ";
    // l.display();
    // l.showHeadTail();

    // cout << "\nlength : " << l.lengthDLL();

    cout << "\nrev : ";
    l.displayReverse();

    return 0;
}