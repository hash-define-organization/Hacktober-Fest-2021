
#include <bits/stdc++.h>
using namespace std;
struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];
int main()
{
    int Mcost[20][20];
    int nodes, i, j, k, count = 0;
    cout << "Enter the number of nodes : ";
    cin >> nodes;
    cout << "Enter the cost of Matrix -\n";
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            scanf("%d", &Mcost[i][j]);
            Mcost[i][i] = 0;
            rt[i].dist[j] = Mcost[i][j];
            rt[i].from[j] = j;
        }
    }
    do
    {
        count = 0;
        for (i = 0; i < nodes; i++)
            for (j = 0; j < nodes; j++)
                for (k = 0; k < nodes; k++)
                    if (rt[i].dist[j] > Mcost[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);
    for (i = 0; i < nodes; i++)
    {
        cout << "\nFor Router : " << i + 1;
        for (j = 0; j < nodes; j++)
        {
            cout << "\t\nNode : " << j + 1 << " via : " << rt[i].from[j] + 1 << " distance : " << rt[i].dist[j];
        }
    }
    cout << "\n\n";
}
