#include <bits/stdc++.h>
#include <string>
#include <graphics.h>
using namespace std;

void Gchart(int start, int end, int num)
{

    setcolor(5);
    settextstyle(3, 0, 1);
    num++;
    rectangle(start * 20 + 100, 150, end * 20 + 100, 200);
    char p[3] = {};
    p[0] = 'P';
    ostringstream str1, str2;
    str2 << num;
    str1 << start;
    string s = str1.str();
    string s2 = str2.str();
    p[1] = s2[0];
    char *c = new char[s.size() + 1];
    int j = 0;
    for (; j < s.size(); j++)
    {
        c[j] = s[j];
    }
    c[j] = '\0';

    outtextxy(start * 20 - 5 + 100, 205, c);
    outtextxy(((start + end) / 2) * 20 + 100 - 10, 165, p);
}

void fun(int arr[], int w[], int n, int q)
{

    int start = 0, end = 0;
    int sum = 0, k;
    int temp[n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
        sum += arr[i];
    }

    int j = 0;
    k = 0;
    while (k < sum)
    {

        int m = j % n;
        if (temp[m] > 0)
        {

            start = end;
            if (temp[m] < q)
                end += temp[m];
            else
                end = end + q;

            Gchart(start, end, m);

            k = k + end - start;
            temp[m] = temp[m] - end + start;
        }

        j++;
    }
}

int main()
{

    initwindow(900, 900);
    int n, time;
    cout << "Enter number of processes : ";
    cin >> n;
    int *arr = new int[n];
    int w[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Burst time of process P" << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Enter the time quantum : ";
    cin >> time;

    fun(arr, w, n, time);

    getch();

    return 0;
}
