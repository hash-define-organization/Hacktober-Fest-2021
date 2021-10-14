#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cout << "Enter mod(Z) value and no : ";
    cin >> n >> m;

    int r1, r2, t1, t2;
    r1 = n;
    r2 = m;
    t1 = 0;
    t2 = 1;
    int q;
    int r, t;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        cout << "\nMultiplicative Inverse for " << m << " in "
             << " Z " << n << " is : " << t1;

    else
        cout << "\nNo Multiplicative Inverse for " << m << " in "
             << " Z " << n << endl;
    return 0;
}
