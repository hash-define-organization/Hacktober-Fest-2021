#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int Pno;
    int burstt;
    int arr;
};

void findWaitingTime(Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].burstt;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {

        for (int j = 0; j < n; j++)
        {
            if ((proc[j].arr <= t) &&
                (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].burstt - proc[shortest].arr;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findavgTime(Process proc[], int n)
{
    // Process *P2 = new Process[n];
    char str[3] = {"P"}, str1[3] = {"p1"};
    int wt[n], tat[n], total_wt = 0, j = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    cout << endl;
    cout << "Processes "
         << " Burst time "
         << " Waiting time " << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        cout << " " << proc[i].Pno << "\t\t" << proc[i].burstt << "\t\t " << wt[i] << endl;
        setcolor(5);
        rectangle(200 + j, 100, 300 + j, 50);
        settextstyle(8, 0, 2);
        sprintf(str, "%d", proc[i].Pno);
        outtextxy(202 + j, 70, "P");
        outtextxy(220 + j, 70, str);
        sprintf(str1, "%d", wt[i]);
        outtextxy(200 + j, 105, str1);
        j += 100;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
}

int main()

{
    initwindow(900, 900);
    int n;
    cout << "Enter no. of processes: ";
    cin >> n;
    Process *P = new Process[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival time of Process " << i + 1 << " : ";
        P[i].Pno = i + 1;
        cin >> P[i].arr;
    }

    for (int i = 0; i < n; i++)
    {

        cout << "Enter Burst time of Process " << i + 1 << " : ";
        cin >> P[i].burstt;
    }

    findavgTime(P, n);

    getch();
    return 0;
}
