#include <iostream>
using namespace std;

class Node
{
  private:
    int data;
    Node *next;
    friend class CLL;

  public:
    Node(int data, Node *next = 0) : data(data), next(next) {}
    ~Node() {}
};

class CLL
{
  private:
    static Node *head;
    Node *tail;

  public:
    CLL() : tail(0) {}
    void insertAtTail(int);
    void reverse();
    void reverseIter(Node *curr = head);
    void showHeadTail() { cout << "  head : " << head << "    tail : " << tail; }
    int lengthCLL(Node *curr = head, int count = 0);
    void display();

    void displayReverse(Node *curr = head)
    {
        if (curr != tail)
        {
            displayReverse(curr->next);
            cout << "  " << curr->data;
        }
        else
            cout << "  " << curr->data;
    }

    ~CLL() {}
};

Node *CLL::head = 0;

void CLL::insertAtTail(int data)
{
    Node *node = new Node(data, head);
    if (head)
    {
        tail->next = node;
        tail = node;
    }
    else
        head = tail = node;
}

void CLL::reverse()
{
    if (head)
    {
        Node *curr = head;
        Node *temp;

        while (curr && curr != tail)
        {
            temp = curr->next;
            if (curr != head)
                curr->next = head;
            else
            {
                curr->next = tail;
                tail = head;
            }
            head = curr;
            curr = temp;
        }
    }
}

void CLL::reverseIter(Node *curr)
{
    if (curr && curr != tail)
    {
        Node *temp = curr->next;
        if (curr != head)
            curr->next = head;
        else
        {
            curr->next = tail;
            tail = head;
        }
        head = curr;
        reverseIter(temp);
    }
}

int CLL::lengthCLL(Node *curr, int count)
{
    if (curr)
    {
        ++count;
        lengthCLL(curr->next, count);
    }
    else
        return count;
}

void CLL::display()
{
    if (head)
    {
        Node *curr = head;
        while (true)
        {
            cout << "  " << curr->data;
            if (curr == tail)
                break;
            curr = curr->next;
        }
    }
}

int main()
{
    int data;
    char ch;

    CLL l;
    cout << "\nEnter CLL : ";
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
    // cout << "\nl it: ";
    // l.display();
    // l.showHeadTail();
    // cout << "\nlength : " << l.lengthCLL();

    cout << "\nrev : ";
    l.displayReverse();

    return 0;
}