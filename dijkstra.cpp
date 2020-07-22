#include <iostream>

using namespace std;

int *findShortest(int **adj_mat, int start, int end)
{
}

int main()
{
    cout << "\nenter no of vertices : ";
    int v;
    cin >> v;

    cout << "\nenter no of edges : ";
    int e;
    cin >> e;

    int **adj_mat = new int *[v];
    for (int i = 0; i < v; i++)
    {
        adj_mat[i] = new int[v];
    }

    cout << "\nenter weight for edges : ";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adj_mat[i][j];
        }
    }

    cout << "\nenter start and end : ";
    int start, end;
    cin >> start >> end;

    int *shortest_path = findShortest(adj_mat, start, end);

    return;
}