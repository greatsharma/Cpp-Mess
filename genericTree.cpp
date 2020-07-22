#include <iostream>
using namespace std;

class Node
{
private:
  int data;
  int noChild;
  Node **childs;
  friend class Tree;

public:
  Node() {}
  Node(int data, int noChild) : data(data), noChild(noChild) { childs = new Node *[noChild]; }
  ~Node() {}
};

class Tree
{
private:
  static Node *root;

public:
  Tree() {}
  void insert(int, int, Node *curr_node = root);
  ~Tree() {}
};

Node *Tree::root = 0;

void Tree::insert(int data, int noOfChilds, Node *curr_node)
{
  Node *node = new Node(data, noOfChilds);
  if (!curr_node)
    root = node;

  if (curr_node)
  {
  }
}

int main()
{
  char ch;
  Tree t;
  do
  {
    cout << "\nMENU : ";
    cout << "\n1. Insert";
    cout << "\n\nEnter your choice : ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      cout << "\nenter data and no of childs : ";
      int data, child;
      cin >> data >> child;
    }
    break;

    default:
      cout << "\nInvalid...";
    }

    cout << "\nEnter 0 to exit : ";
    cin >> ch;
  } while (ch != '0');

  return 0;
}