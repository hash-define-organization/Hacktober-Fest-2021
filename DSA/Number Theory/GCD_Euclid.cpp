#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cout << "Enter the numbers : ";
    cin >> n >> m;

    int r1, r2;
    r1 = n;
    r2 = m;

    int q;
    int r;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
    }

    cout << "GCD of the no : " << n << " , " << m << " is : " << r1;
    return 0;
}
