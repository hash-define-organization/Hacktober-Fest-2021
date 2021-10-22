/* Program to perform Insertion , Deletion  and Display of 
   all elements in Queue as an Array [FIFO] .
   By using menu driven code.

 */

#include <bits/stdc++.h>
using namespace std;

int front = -1;
int rear = -1;

void insert(int A[], int s, int val)
{

    if (rear < s - 1)
    {
        A[++rear] = val;

        if (front == -1)
        {
            front = 0;
        }
    }

    else
        cout << "Queue overflow condition" << endl;
}

int remove(int A[])
{

    if (front == -1)
    {
        cout << "Queue Underflow condition" << endl;
        return -1;
    }
    else
    {
        int x = A[front];
        front++;
        cout << "deleted:" << x;
    }
    if (front > rear)
    {
        front = rear = -1;
    }
}

void display(int A[])
{

    int t = front;
    while (t <= rear)
    {

        cout << A[t] << endl;
        t++;
    }

    cout << "End of Queue";
}

int main()
{

    int arr[15];
    int val;

    int c;

    do
    {

        cout << "Enter choice \n"
             << "\n 1.Insert a new element to Queue \n"
             << "\n 2. Delete first element in queue \n"
             << "\n 3.Display all elements \n"
             << "\n 4.Exit ";

        cin >> c;

        switch (c)
        {

        case 1:
            cout << "Enter the value to be inserted in queue:";
            cin >> val;
            insert(arr, 15, val);
            break;

        case 2:
            int z = remove(arr);
            if (z == -1)
            {
                cout << "Continue with this loop";
            }
            break;

        case 3:
            display(arr);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\n Invalid Choice";
        }
    } while (c != 4);
    return 0;
}
