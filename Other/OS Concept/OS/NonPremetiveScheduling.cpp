#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

struct process
{
    char process_name;
    int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
    int status;
} pro_que[10];

int limit;

void Arrival_time()
{
    struct process temp;
    int i, j;
    for (i = 0; i < limit - 1; i++)
    {
        for (j = i + 1; j < limit; j++)
        {
            if (pro_que[i].arrival_time > pro_que[j].arrival_time)
            {
                temp = pro_que[i];
                pro_que[i] = pro_que[j];
                pro_que[j] = temp;
            }
        }
    }
}

int main()
{
    initwindow(900, 900);
    int i, time = 0, burst_time = 0, largest;
    char c;
    int j = 0;
    char str[3] = {"P"}, str1[3] = {"p1"};
    cout << "Non-Pre-\n";

    float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
    cout << "\nEnter Total Number of Processes : ";
    cin >> limit;
    for (i = 0; i < limit; i++)
    {
        pro_que[i].process_name = i + 1;
        cout << "Enter Arrival,Burst and Priority of Process  " << i + 1 << " : ";
        cin >> pro_que[i].arrival_time >> pro_que[i].burst_time >> pro_que[i].priority;
        pro_que[i].status = 0;
        burst_time = burst_time + pro_que[i].burst_time;
    }
    Arrival_time();
    pro_que[9].priority = -9999;
    cout << "\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time ";
    for (time = pro_que[0].arrival_time; time < burst_time;)
    {
        largest = 9;
        for (i = 0; i < limit; i++)
        {
            if (pro_que[i].arrival_time <= time && pro_que[i].status != 1 && pro_que[i].priority > pro_que[largest].priority)
            {
                largest = i;
            }
        }
        time = time + pro_que[largest].burst_time;
        pro_que[largest].ct = time;
        pro_que[largest].waiting_time = pro_que[largest].ct - pro_que[largest].arrival_time - pro_que[largest].burst_time;
        pro_que[largest].turnaround_time = pro_que[largest].ct - pro_que[largest].arrival_time;
        pro_que[largest].status = 1;
        wait_time = wait_time + pro_que[largest].waiting_time;
        turnaround_time = turnaround_time + pro_que[largest].turnaround_time;

        setcolor(5);
        rectangle(200 + j, 100, 300 + j, 50);
        settextstyle(8, 0, 2);
        sprintf(str, "%d", pro_que[largest].process_name);
        outtextxy(202 + j, 70, "P");
        outtextxy(220 + j, 70, str);
        sprintf(str1, "%d", pro_que[largest].waiting_time);
        outtextxy(200 + j, 105, str1);
        j += 100;

            cout<<"\n%d\t\t%d\t\t%d\t\t%d\t\t%d"<<pro_que[largest].process_name<<pro_que[largest].arrival_time
            <<pro_que[largest].burst_time<<pro_que[largest].priority<< pro_que[largest].waiting_time);

            average_waiting_time = wait_time / limit;

            cout << "\n\nAverage waiting time:\t%f\n"
                 << (average_waiting_time);

            getch();
            return 0;
    }
