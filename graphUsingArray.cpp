#include <iostream>
#include <conio.h>
#include <queue>
#include <stack>

#define INFINITY 10000
#define WHITE 0 // Not discovered
#define GREY 1  // Discovered
#define BLACK 2 // Done

#define RED 1
#define GREEN 2

using namespace std;

class Node
{
  public:
    int val;
    Node *next;
    Node(int val) : val(val), next(0) {}
};

class Graph
{
  public:
    int no_v;
    Node **adj;

    Graph(int no_v) : no_v(no_v)
    {
        adj = new Node *[no_v];
        for (int i = 0; i < no_v; ++i)
        {
            adj[i] = 0;
        }
    }

    void addEdge(const int u, const int v)
    {
        Node *new_node = new Node(v);

        if (!adj[u])
        {
            adj[u] = new_node;
        }
        else
        {
            new_node->next = adj[u];
            adj[u] = new_node;
        }
    }

    Node **getAdjList() const
    {
        return adj;
    }
};

void initialise_array(int *Arr, const int len, const int val)
{
    for (int i = 0; i < len; i++)
    {
        Arr[i] = val;
    }
}

void BFS(const Graph g, const int src, int *levelArr)
{
    queue<int> q;
    int discArr[g.no_v];
    initialise_array(discArr, g.no_v, WHITE);

    q.push(src);
    levelArr[src] = 0;
    discArr[src] = GREY;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        discArr[v] = BLACK;
        int parent_level = levelArr[v];

        Node *ptr = g.adj[v];
        while (ptr)
        {
            if (discArr[ptr->val] == WHITE)
            {
                q.push(ptr->val);
                discArr[ptr->val] = GREY;
                levelArr[ptr->val] = parent_level + 1;
            }
            ptr = ptr->next;
        }
    }
}

void DFS(const Graph g, const int src, int *vParent)
{
    stack<int> s;
    int discArr[g.no_v];
    initialise_array(discArr, g.no_v, WHITE);

    s.push(src);
    discArr[src] = GREY;
    vParent[src] = -1; // added

    cout << "\ndfs trace: ";
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        cout << " " << v;
        discArr[v] = BLACK;

        Node *ptr = g.adj[v];
        while (ptr)
        {
            if (discArr[ptr->val] == GREY)
            {
                vParent[ptr->val] = v;
            }
            if (discArr[ptr->val] == WHITE)
            {
                s.push(ptr->val);
                vParent[ptr->val] = v; // added
                discArr[ptr->val] = GREY;
            }
            ptr = ptr->next;
        }
    }
}

int select_vertex(int discArr[], const int no_v)
{
    static int i = 0;
    for (int i = 0; i < no_v; ++i)
    {
        if (discArr[i] == WHITE)
            return i;
    }
    return -1;
}

bool bipartite(const Graph g)
{
    queue<int> q;
    int discArr[g.no_v];
    initialise_array(discArr, g.no_v, WHITE);
    int colorArr[g.no_v] = {int()};

    while (true)
    {
        int src = select_vertex(discArr, g.no_v);
        if (src == -1)
        {
            return true;
        }

        q.push(src);
        discArr[src] = GREY;
        colorArr[src] = RED;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            discArr[v] = BLACK;

            Node *ptr = g.adj[v];
            while (ptr)
            {
                if (discArr[ptr->val] == WHITE)
                {
                    q.push(ptr->val);
                    discArr[ptr->val] = GREY;

                    if (colorArr[v] == RED)
                        colorArr[ptr->val] = GREEN;
                    else
                        colorArr[ptr->val] = RED;
                }
                else
                {
                    if (colorArr[v] == colorArr[ptr->val])
                        return false;
                }

                ptr = ptr->next;
            }
        }
    }
}

void show_graph(const Graph g)
{
    cout << "\nGraph: \n";
    for (int i = 0; i < g.no_v; i++)
    {
        cout << i << " ->  ";
        Node *ptr = g.adj[i];
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

void test()
{
    // paste tests here from graphTests.txt
}

int main()
{
    // #define TEST // Uncomment this for running predefined test in graphTest.txt.
    //     test();  // Uncomment this for running predefined test in graphTest.txt.

#ifndef TEST

    cout << "\nenter no of vertices : ";
    int no_v;
    cin >> no_v;

    Graph graph(no_v);

    cout << "enter 0 for directed and 1 for undirected graph : ";
    int choice;
    cin >> choice;
    cout << "\nenter (u,v) pair in the graph (-1 to exit): ";
    int u, v;

    while (true)
    {
        cin >> u;
        if (u == -1)
            break;

        cin >> v;
        graph.addEdge(u, v);

        if (choice == 1)
            graph.addEdge(v, u);
    }

    show_graph(graph);
    cout << "\nenter source : ";
    int src;
    cin >> src;

    int level[no_v], vParent[no_v];
    for (int i = 0; i < no_v; i++)
    {
        level[i] = INFINITY;
        vParent[i] = INFINITY;
    }

    cout << "\nBFS " << INFINITY << " represents not reachable: ";
    BFS(graph, src, level);
    for (int i = 0; i < no_v; i++)
    {
        cout << "\n"
             << level[i];
    }

    cout << "\n\nDFS " << INFINITY << " represents not reachable: ";
    DFS(graph, src, vParent);
    for (int i = 0; i < no_v; i++)
    {
        cout << "\n"
             << vParent[i];
    }

    if (bipartite(graph))
        cout << "\n\nis bipartite";
    else
        cout << "\n\nnot bipartite";

#endif // !TEST

    getch();
    return 0;
}