//Given an integer n and a prime number p, find the largest x such that px (p raised to power x) divides n!

#include <iostream>
using namespace std;

int largestPower(int n, int p)
{

    int x = 0;

    while (n)
    {
        n /= p;
        x += n;
    }
    return x;
}

// Driver code
int main()
{
    int n, p;
    cin >> n >> p;
    cout << "The largest Power of " << p << " that divides " << n << "! is " << largestPower(n, p) << endl;
    return 0;
}
