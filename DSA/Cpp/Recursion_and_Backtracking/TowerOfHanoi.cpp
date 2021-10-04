#include <bits/stdc++.h>
using namespace std;

void TOH(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    TOH(n - 1, a, c, b);
    cout << n << " [ " << a << " -> " << b << " ]" << endl;
    TOH(n - 1, c, b, a);
}

int main()
{
    TOH(3, 'A', 'B', 'C');
    return 0;
}