#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
  Node<T> *next;
  T data;
  friend class SLL;

public:
  Node(T data, Node<T> *next = 0) : next(next), data(data) {}
  ~Node() {}
};

template <class T>
class SLL
{
private:
  Node<T> *head;
  Node<T> *tail;

public:
  void insertHead(T);
};

template <class T>
void SLL<T>::insertHead(T data)
{
  {
    cout << "\ndo " << data;
  }
}

int main()
{

  SLL<int> obj;
  obj.insertHead(5);
  cin.get();
  return 0;
}