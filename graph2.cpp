#include <iostream>

using std::cin;
using std::cout;

class NodeEdge;

class NodeVertex
{
  private:
    char _m_vertex;
    int _m_in_deg;
    int _m_out_deg;

    NodeVertex *next;
    NodeEdge *out_edge_list;
    NodeEdge *in_edge_list;

    friend class NodeEdge;
    friend class Graph;

  public:
    NodeVertex(char _vertex, int _in_deg, int _out_deg, NodeVertex *next = 0)
    {
        _m_vertex = _vertex;
        _m_in_deg = _in_deg;
        _m_out_deg = _out_deg;
        this->next = next;
        out_edge_list = 0;
        in_edge_list = 0;
    }

    ~NodeVertex() {}
};

class NodeEdge
{
  private:
    char _m_edge;
    NodeEdge *next;

    friend class Graph;

  public:
    NodeEdge(char _data, NodeEdge *next = 0) : _m_edge(_data), next(next) {}
    ~NodeEdge() {}
};
/*
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
*/
class Graph
{
  private:
    NodeVertex *head;

  public:
    Graph()
    {
        head = 0;

        cout << "\nGraph Created :)\n";
    }

    void add_vertex_with_edges(char _vertex, char _in_edges[], char _out_edges[], int _no_in_e, int _no_out_e)
    {
        NodeVertex *_new_vertex = new NodeVertex(_vertex, _no_in_e, _no_out_e, head);
        head = _new_vertex;

        if (_no_in_e > 0)
            _new_vertex->in_edge_list = new NodeEdge(_in_edges[0]);

        for (int i = 1; i < _no_in_e; i++)
        {
            NodeEdge *temp = _new_vertex->in_edge_list;
            _new_vertex->in_edge_list = new NodeEdge(_in_edges[i], temp);
        }

        if (_no_out_e > 0)
            _new_vertex->out_edge_list = new NodeEdge(_out_edges[0]);

        for (int i = 1; i < _no_out_e; i++)
        {
            NodeEdge *temp = _new_vertex->out_edge_list;
            _new_vertex->out_edge_list = new NodeEdge(_out_edges[i], temp);
        }

        return;
    }

    void transpose()
    {
        NodeVertex *curr_node = head;

        if (curr_node)
        {
            NodeEdge *temp = curr_node->out_edge_list;
            curr_node->out_edge_list = curr_node->in_edge_list;
            curr_node->in_edge_list = temp;
        }

        return;
    }

    /* void add_edges(char _vertex, char _edges[], int _no_e)
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
*/
    void show_graph()
    {
        NodeVertex *curr_node = head;

        while (curr_node)
        {
            cout << "\n";

            if (curr_node->in_edge_list)
            {
                NodeEdge *temp = curr_node->in_edge_list;

                while (temp)
                {
                    cout << " " << temp->_m_edge;
                    temp = temp->next;
                }
            }

            cout << " -> {" << curr_node->_m_vertex << "} -> ";

            if (curr_node->out_edge_list)
            {
                NodeEdge *temp = curr_node->out_edge_list;

                while (temp)
                {
                    cout << " " << temp->_m_edge;
                    temp = temp->next;
                }
            }

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
    char *in_edg;
    char *out_edg;
    char v;
    int n;
    int in;
    int out;

    cout << "\n\n========MENU========";
    cout << "\n\n1. Add Vertex With Edges";
    cout << "\n2. Add Edges";
    cout << "\n3. Delete Vertex";
    cout << "\n4. Delete Edges";
    cout << "\n5.Transpose";
    cout << "\n6. Display";

    cout << "\n\nEnter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        cout << "\nEnter vertex to be inserted : ";
        cin >> v;

        cout << "\nEnter in  and out degree : ";
        cin >> in >> out;

        in_edg = new char[in];
        out_edg = new char[out];

        cout << "\nEnter in edges to the vertex " << v << " : ";

        for (int i = 0; i < in; i++)
            cin >> in_edg[i];

        cout << "\nEnter out edges to the vertex " << v << " : ";

        for (int i = 0; i < out; i++)
            cin >> out_edg[i];

        graph.add_vertex_with_edges(v, in_edg, out_edg, in, out);
        graph.show_graph();

        break;

    case 5:
        graph.transpose();
        graph.show_graph();
        break;
        /*
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
*/
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
