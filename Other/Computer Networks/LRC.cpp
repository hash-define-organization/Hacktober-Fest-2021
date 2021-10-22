#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n, count = 0;
    char str1[20], str2[4][5];
    string str3[4][1];
    cout << "Enter 16-bits msg : \n";
    cin.getline(str1, 20);
    n = strlen(str1);
    int j, i = 0;
    for (j = 0; j < 4; j++, i++)
        str2[0][i] = str1[j];
    for (i = 0, j = 4; j < 8; j++, i++)
        str2[1][i] = str1[j];
    for (i = 0, j = 8; j < 12; j++, i++)
        str2[2][i] = str1[j];
    for (i = 0, j = 12; j < 16; j++, i++)
        str2[3][i] = str1[j];
    cout << "\nEntered msg is - " << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            cout << str2[i][j];
        cout << " ";
    }
    for (i = 0; i < 4; i++)
    {
        count = 0;
        for (j = 0; j < 4; j++)
            if (str2[j][i] == '1')
                count++;
        if (count % 2 == 0)
        {
            str2[i][5] = '0';
        }
        else
        {
            str2[i][5] = '1';
        }
    }
    cout << "\nMessage after LRC - " << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            cout << str2[i][j];
        cout << " ";
    }
    for (i = 0; i < 4; i++)
    {
        cout << str2[i][5];
    }
    return 0;
}
