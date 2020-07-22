#include <iostream>
using namespace std;

int *sort_at(int *at, int *process, int size)
{
    static int *s_at = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        s_at[i] = at[i];

    for (int i = 0; i < size; i++)
    {
        int k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (s_at[i] > s_at[j])
            {
                int temp = s_at[j];
                s_at[j] = s_at[i];
                s_at[i] = temp;
                k = j;
            }
        }
        process[i] = k + 1;
    }
    return s_at;
}

int main(void)
{
    cout << "\nROUND ROBIN ::\)\n";
    cout << "\nEnter no of processes : ";
    int p;
    cin >> p;

    cout << "\nenter arrival time : ";
    int *at = (int *)calloc(p, sizeof(int));
    for (int i = 0; i < p; i++)
        cin >> at[i];

    int *process = (int *)calloc(p, sizeof(int));
    int *ptr = sort_at(at, process, p);

    cout << "\nprocess : ";
    for (int i = 0; i < p; i++)
        cout << "  " << process[i];

    cout << "\nenter burst time : ";
    int *bt = (int *)calloc(p, sizeof(int));
    for (int i = 0; i < p; i++)
    {
        cin >> bt[i];
    }

    cout << "\nenter time quantum : ";
    int t_q;
    cin >> t_q;

    bool *avail = (bool *)calloc(p, sizeof(bool));
    for (int i = 0; i < p; i++)
    {
        avail[i] = false;
        process[i] = i + 1;
    }

    while (true)
    {
    }

    free(at), free(bt), free(avail), free(process);
    system("pause");
    return 0;
}