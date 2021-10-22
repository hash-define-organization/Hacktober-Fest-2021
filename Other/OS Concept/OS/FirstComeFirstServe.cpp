#include <iostream>
#include <graphics.h>
using namespace std;

void findWaitingTime(int processes[], int n,
                     int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findavgTime(int p[], int n, int bt[])
{
    int j = 0;
    char str[3] = {“P”};
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(p, n, bt, wt);
    cout << endl;
    cout << "Processes "
         << " Burst time "
         << " Waiting time ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t ";
        cout << endl;
        setcolor(5);
        rectangle(200 + j, 100, 300 + j, 50);
        settextstyle(8, 0, 2);

        sprintf(str, "%d", i + 1);

        outtextxy(205 + j, 95, str);
        j += 100;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
}

int main()
{
    int n, p[30], bt[30];
    cout << "Enter no. of processes : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Burst Time of Process : " << i + 1 << " : ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    findavgTime(p, n, bt);
    return 0;
}
