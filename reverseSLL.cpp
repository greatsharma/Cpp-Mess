#include <iostream>
using namespace std;

class Node
{
  private:
    int data;
    Node *next;
    friend class SLL;

  public:
    Node(int data, Node *next = 0) : data(data), next(next) {}
    ~Node() {}
};

class SLL
{
  private:
    static Node *head;
    Node *tail;

  public:
    SLL() : tail(0) {}
    void insertAtTail(int);
    void reverse();
    void reverseIter(Node *curr = head);
    void showHeadTail() { cout << "  head : " << head << "    tail : " << tail; }
    int lengthSLL(Node *curr = head, int count = 0);
    void display();

    void displayReverse(Node *curr = head)
    {
        if (curr)
        {
            displayReverse(curr->next);
            cout << "  " << curr->data;
        }
    }

    ~SLL() {}
};

Node *SLL::head = 0;

void SLL::insertAtTail(int data)
{
    Node *node = new Node(data);
    if (head)
    {
        tail->next = node;
        tail = node;
    }
    else
        head = tail = node;
}

void SLL::reverse()
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
            head = curr;
            curr = temp;
        }
    }
}

void SLL::reverseIter(Node *curr)
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
        head = curr;
        reverseIter(temp);
    }
}

int SLL::lengthSLL(Node *curr, int count)
{
    if (curr)
    {
        ++count;
        lengthSLL(curr->next, count);
    }
    else
        return count;
}

void SLL::display()
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

    SLL l;
    cout << "\nEnter SLL : ";
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
    // cout << "\nl : ";
    // l.display();
    // l.showHeadTail();

    // cout << "\nlength : " << l.lengthSLL();
    cout << "\nrev : ";
    l.displayReverse();
    return 0;
}