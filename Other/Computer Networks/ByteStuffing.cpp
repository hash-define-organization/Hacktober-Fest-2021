
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char frame[50][50], str[50][50];
    char flag[10];
    char esc[10];
    int i, j, k = 0, n;
    strcpy(frame[k++], "001 "); //flag=001
    cout << "Enter no.of Packets to send  :\t";
    cin >> n;
    cout << "\nEnter msg of each packet \n";
    for (i = 0; i <= n; i++)
    {
        gets(str[i]);
    }
    cout << "\n";

    for (i = 1; i <= n; i++)
    {
        if (strcmp(str[i], "001") != 0 && strcmp(str[i], "esc") != 0)
        {
            strcpy(frame[k++], str[i]);
        }
        else
        {
            strcpy(frame[k++], " esc ");
            strcpy(frame[k++], str[i]);
        }
    }
    strcpy(frame[k++], " 001 ");
    cout << "Msg After Byte stuffing - \n";
    for (i = 0; i < k; i++)
    {
        cout << frame[i] << " ";
    }
    cout << endl;
    return 0;
}
