#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
void swap(int *a, int *b);

int matrix[10][6];
void arrangeArrival(int num, int mat[][6]);
void completionTime(int num, int mat[][6]);

int main()
{
    int num, temp;
    initwindow(900, 900);

    cout << "Enter number of Process : ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter Arrival Time of Process P " << i + 1 << " : ";
        cin >> matrix[i][1];
    }

    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter Burst Time of Process P " << i + 1 << " : ";
        cin >> matrix[i][2];
    }

    cout << "\nProcess \tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++)
    {
        cout << "P " << i + 1 << "\t\t" << matrix[i][1] << "\t\t" << matrix[i][2] << "\n";
    }

    arrangeArrival(num, matrix);
    completionTime(num, matrix);
    cout << "\nAfter Non Premitive job Scheduling \n";
    cout << "\nProcess \tArrival Time\tBurst Time\tWaiting Time\n";
    int j = 0;
    char str[3] = {"P"}, str1[3] = {"p1"};
    int avg = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "P  " << i + 1 << "\t\t" << matrix[i][1] << "\t\t" << matrix[i][2] << "\t\t" << matrix[i][4] << endl;
        avg += matrix[i][4];
        setcolor(5);
        rectangle(200 + j, 100, 300 + j, 50);
        settextstyle(8, 0, 2);
        sprintf(str, "%d", matrix[i][1]);
        outtextxy(202 + j, 70, "P");
        outtextxy(220 + j, 70, str);
        sprintf(str1, "%d", matrix[i][4]);
        outtextxy(200 + j, 105, str1);
        j += 100;
    }

    cout << "\nAverage waiting Time : " << (float)avg / (float)num;

    getch();
    return 0;
}

void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (mat[j][1] > mat[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    swap(mat[j][k], mat[j + 1][k]);
                }
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];

    for (int i = 1; i < num; i++)
    {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(mat[val][k], mat[i][k]);
        }
    }
}
