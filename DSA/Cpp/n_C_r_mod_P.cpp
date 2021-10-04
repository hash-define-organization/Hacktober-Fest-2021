#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, r;
    cin >> n >> r;
    // we will use the general formula
    //    C(n, r)%p = [ C(n-1, r-1)%p + C(n-1, r)%p ] % p
    //    C(n, 0) = C(n, n) = 1
    const int mod = 1e9 + 7;
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    // this function creates pascal triangle

    for (int ind = 0; ind <= n; ind++) //  nCr , ind= n , n=[0,1,2..];
    {
        for (int curr = min(ind, r); curr > 0; curr--) // nCr curr=r , r= [0,1,2..  (r<=n)]
        {                                              
            C[curr] = (C[curr] + C[curr - 1]) % mod;  // nCj = (n-1)Cj + (n-1)C(j-1);
        }
    }

    //if n and r don't satisfy binomial coefficient condition then ans will be 0
    // For example on situation where R > N
    if (!C[r])
        cout << C[r] << endl;
    else
        cout << 0 << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}