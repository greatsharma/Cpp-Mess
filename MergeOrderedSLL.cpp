#include <iostream>
#include "conio.h"
using namespace std;

class Node
{
  private:
    int data;
    Node *next;
    friend class OLL;

  public:
    Node(int data, Node *next = 0) : data(data), next(next) {}
    ~Node() {}
};

class OLL
{
  private:
    Node *head;
    Node *tail;

  public:
    OLL() : head(0), tail(0) {}
    void insertAtTail(int);
    OLL mergeOLL(OLL *);
    void display();
    ~OLL() {}
};

void OLL::insertAtTail(int data)
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

OLL OLL::mergeOLL(OLL *obj)
{
    Node *curr1 = head, *curr2 = obj->head;
    OLL l3;

    while (curr1 && curr2)
    {
        if (curr1->data < curr2->data)
        {
            l3.insertAtTail(curr1->data);
            curr1 = curr1->next;
        }
        else if (curr2->data < curr1->data)
        {
            l3.insertAtTail(curr2->data);
            curr2 = curr2->next;
        }
        else
        {
            l3.insertAtTail(curr2->data);
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
    }

    while (curr1)
    {
        l3.insertAtTail(curr1->data);
        curr1 = curr1->next;
    }

    while (curr2)
    {
        l3.insertAtTail(curr2->data);
        curr2 = curr2->next;
    }

    return l3;
}

void OLL::display()
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

    OLL l1;
    cout << "\nEnter OLL 1 : ";
    do
    {
        cout << "\nEnter node data : ";
        cin >> data;
        l1.insertAtTail(data);

        cout << "\nenter 0 to exit : ";
        cin >> ch;
    } while (ch != '0');

    cout << "\nl1 : ";
    l1.display();

    OLL l2;
    cout << "\nEnter OLL 2 : ";
    do
    {
        cout << "\nEnter node data : ";
        cin >> data;
        l2.insertAtTail(data);

        cout << "\nenter 0 to exit : ";
        cin >> ch;
    } while (ch != '0');

    OLL l3 = l1.mergeOLL(&l2);
    cout << "\nl1 : ";
    l1.display();
    cout << "\nl2 : ";
    l2.display();
    cout << "\nl3 : ";
    l3.display();

    // cin.get();
    getch();
    return 0;
}
