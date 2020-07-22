/*
Name: RED BLACK TREE
Author: Gaurav Sharma
Date: 28-04-19 19:09
Description: A simple c++ program to create a red black tree with insert and delete operations.
*/
#include <iostream>
#include <conio.h>

#define RED 1
#define BLACK 0

using namespace std;

class Node
{
  private:
    int val;
    int color;
    Node *right;
    Node *left;
    Node *parent;

    friend class RBT;

  public:
    Node(int val, int color = RED, Node *right = 0, Node *left = 0, Node *parent = 0)
        : val(val), color(color), right(right), left(left), parent(parent) {}
};

class RBT
{
  public:
    RBT() : root(0), NIL(new Node(-1, BLACK)) {}

    Node *getRootByAddr() const
    {
        return root;
    }

    void insert(int val)
    {
        Node *node = new Node(val, RED, NIL, NIL, NIL);

        if (root)
        {
            Node *temp = root;
            Node *ptr;

            while (temp != NIL)
            {
                ptr = temp;
                if (temp->val < val)
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            if (ptr->val < val)
                ptr->right = node;
            else
                ptr->left = node;

            node->parent = ptr;
            insertFixup(node);
        }
        else
        {
            root = node;
            root->color = BLACK;
        }
    }

    void deleteNode(int val)
    {
        Node *z = findNode(val);
        if (z != NIL)
        {
            Node *y, *x;
            y = (z->left == NIL || z->right == NIL) ? z : successor(z);
            x = (z->left != NIL) ? y->left : y->right;

            x->parent = y->parent;

            if (y->parent == NIL)
                root = x;
            else if (y == y->parent->left)
                y->parent->left = x;
            else
                y->parent->right = x;

            if (y != z)
                z->val = y->val;

            if (y->color == BLACK)
                deleteFixup(x);

            delete y;
        }
    }

    void showFullHorizontal(const Node *ptr, int space = 0) const
    {
        if (!ptr)
            return;

        space++;
        showFullHorizontal(ptr->right, space);
        for (int i = 1; i < space; i++)
            std::cout << "	  ";

        if (ptr->color == RED)
            std::cout << "R " << ptr->val << "\n";
        else
            std::cout << "B " << ptr->val << "\n";

        showFullHorizontal(ptr->left, space);
    }

  private:
    Node *root;
    Node *NIL;

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != NIL)
            y->left->parent = x;

        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->parent = x->parent;
        x->parent = y;
        y->left = x;
    }

    void rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;

        if (y->right != NIL)
            y->right->parent = x;

        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->parent = x->parent;
        x->parent = y;
        y->right = x;
    }

    void insertFixup(Node *z)
    {
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *u = z->parent->parent->right;

                if (u->color == RED)
                {
                    u->color = BLACK;
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                else
                {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node *u = z->parent->parent->left;

                if (u->color == RED)
                {
                    u->color = BLACK;
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                else
                {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    Node *findNode(const int val) const
    {
        Node *temp = root;
        while (temp != NIL || temp->val != val)
        {
            if (temp->val < val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return temp;
    }

    Node *successor(const Node *z) const
    {
        Node *temp = z->right;
        if (temp != NIL)
        {
            while (temp->left != NIL)
                temp = temp->left;
        }
        return temp;
    }

    void deleteFixup(Node *x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                Node *w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                else if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                else
                {
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                Node *w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                else if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                else
                {
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
};

int main()
{
    RBT tree;

    tree.insert(10);
    cout << "\n\ninsert: 10\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());
    tree.insert(5);
    cout << "\n\ninsert: 5\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());
    tree.insert(20);
    cout << "\n\ninsert: 20\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());
    tree.insert(1);
    cout << "\n\ninsert: 1\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());
    tree.insert(18);
    cout << "\n\ninsert: 18\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());
    tree.insert(9);
    cout << "\n\ninsert: 9\n\n";
    tree.showFullHorizontal(tree.getRootByAddr());

    getch();
    return 0;
}