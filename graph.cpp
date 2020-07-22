#include <iostream>

using std::cin;
using std::cout;

class SinglyLinkedList;

class Node
{
private:
  char _m_data;
  Node *next;
  SinglyLinkedList *edge_list;

  friend class SinglyLinkedList;
  friend class Graph;

public:
  Node(char _data, Node *next = 0, SinglyLinkedList *edge_list = 0) : _m_data(_data), next(next), edge_list(edge_list) {}
  ~Node() {}
};

class SinglyLinkedList
{
private:
  Node *head;

  friend class Node;
  friend class Graph;

public:
  SinglyLinkedList()
  {
    head = 0;
  }

  void add_node_head(char _data)
  {
    Node *new_node = new Node(_data, head);
    head = new_node;

    return;
  }

  void remove_node(char _find)
  {
    Node *curr_node = head;

    if (curr_node->_m_data != _find)
    {
      while (curr_node->next->_m_data != _find)
      {
        curr_node = curr_node->next;
      }

      Node *node_remove = curr_node->next;
      curr_node->next = node_remove->next;

      if (node_remove->edge_list)
        node_remove->edge_list->delete_list();

      delete node_remove;
    }
    else
    {
      Node *new_head = curr_node->next;
      delete head;
      head = new_head;
    }

    return;
  }

  Node *find_node(char _find)
  {
    Node *curr_node = head;

    while (curr_node->_m_data != _find)
      curr_node = curr_node->next;

    return curr_node;
  }

  void delete_list()
  {
    Node *curr_node = head;

    while (curr_node)
    {
      Node *temp = curr_node->next;
      delete curr_node;
      curr_node = temp;
    }

    return;
  }

  int total_nodes()
  {
    Node *curr_node = head;
    int counter = 0;

    while (!curr_node)
    {
      ++counter;
      curr_node = curr_node->next;
    }

    return counter;
  }

  void show_sll()
  {
    Node *curr_node = head;

    while (curr_node)
    {
      cout << "  " << curr_node->_m_data;
      curr_node = curr_node->next;
    }

    return;
  }

  ~SinglyLinkedList() {}
};

class Graph
{
private:
  SinglyLinkedList *vertices;

public:
  Graph()
  {
    vertices = new SinglyLinkedList();

    cout << "\nGraph Created :)\n";
  }

  void add_vertex(char _vertex[], int _no_v)
  {
    for (int i = 0; i < _no_v; i++)
    {
      vertices->add_node_head(_vertex[i]);
      vertices->head->edge_list = new SinglyLinkedList();
    }
    return;
  }

  void add_edges(char _vertex, char _edges[], int _no_e)
  {
    Node *curr = vertices->find_node(_vertex);

    for (int i = 0; i < _no_e; i++)
    {
      curr->edge_list->add_node_head(_edges[i]);
    }

    return;
  }

  void remove_vertex(char _vertex[], int _no_v)
  {
    for (int i = 0; i < _no_v; i++)
      vertices->remove_node(_vertex[i]);

    return;
  }

  void remove_edges(char _vertex, char _edges[], int _no_e)
  {
    Node *curr = vertices->find_node(_vertex);

    for (int i = 0; i < _no_e; i++)
    {
      curr->edge_list->remove_node(_edges[i]);
    }

    return;
  }

  void show_graph()
  {
    Node *curr_node = vertices->head;

    while (curr_node)
    {
      cout << "\n  "
           << curr_node->_m_data;

      cout << " -> ";

      if (curr_node->edge_list)
        curr_node->edge_list->show_sll();

      curr_node = curr_node->next;
    }

    return;
  }

  ~Graph()
  {
    cout << "\nGraph Destroyed...";
  }
};

int choice;

void menu(Graph &graph)
{
  char *ver;
  char *edg;
  char v;
  int n;

  cout << "\n\n========MENU========";
  cout << "\n\n1. Add Vertex";
  cout << "\n2. Add Edges";
  cout << "\n3. Delete Vertex";
  cout << "\n4. Delete Edges";
  cout << "\n5. Display";

  cout << "\n\nEnter your choice : ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    cout << "\nEnter no of vertices to be added : ";
    cin >> n;

    ver = new char[n];

    cout << "\nEnter vertices to be inserted : ";

    for (int i = 0; i < n; i++)
      cin >> ver[i];

    graph.add_vertex(ver, n);
    graph.show_graph();

    break;

  case 2:
    cout << "\nEnter vertex from which new edges imerge : ";
    cin >> v;

    cout << "\nEnter no of edges to be added : ";
    cin >> n;

    edg = new char[n];

    cout << "\nEnter all vertices to which new edges merge : ";
    for (int i = 0; i < n; i++)
      cin >> edg[i];

    graph.add_edges(v, edg, n);
    graph.show_graph();

    break;

  case 3:
    cout << "\nEnter no of vertices to be deleted : ";
    cin >> n;

    ver = new char[n];

    cout << "\nEnter vertices to be deleted : ";

    for (int i = 0; i < n; i++)
      cin >> ver[i];

    graph.remove_vertex(ver, n);
    graph.show_graph();

    break;

  case 4:
    cout << "\nEnter vertex from which edges to be deleted imerge : ";
    cin >> v;

    cout << "\nEnter no of edges to be deleted : ";
    cin >> n;

    edg = new char[n];

    cout << "\nEnter vertices to which deleting edges merge : ";
    for (int i = 0; i < n; i++)
      cin >> edg[i];

    graph.remove_edges(v, edg, n);
    graph.show_graph();

    break;

  case 5:
    graph.show_graph();
    break;

  default:
    cout << "\nInvalid choice !";
  }

  return;
}

void make_graph()
{
  Graph graph;
  while (true)
  {
    menu(graph);
    cout << "\n\nEnter 0 to exit : ";
    cin >> choice;
    if (choice == 0)
      break;
  }

  return;
}

int main(void)
{
  do
  {
    make_graph();
    cout << "\n\nwant to make new graph(if not press 0)? ";
    cin >> choice;
  } while (choice != 0);

  return 0;
}
