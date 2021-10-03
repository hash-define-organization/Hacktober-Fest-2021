// Find the value of  "s" and "t"  for equation { s × a + t × b = gcd (a, b) } and GCD of two number
// It is use to find the particular solution of Linear Diophantine Equations
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cout << "Enter two number to find GCD : ";
    cin >> n >> m;

    int r1, r2, t1, t2;
    r1 = n;
    r2 = m;
    t1 = 0;
    t2 = 1;
    int s1 = 1, s2 = 0;
    int q;
    int r, t, s;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
        s = s1 - q * s2;
        s1 = s2;
        s2 = s;
    }

    cout << "GCD of no is : " << r1 << endl;
    cout << "Value of s is : " << s1 << " and t is : " << t1;
    return 0;
}
