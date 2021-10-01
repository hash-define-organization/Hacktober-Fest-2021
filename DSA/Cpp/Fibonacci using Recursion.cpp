#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#include <bits/stdc++.h>
 
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define ll long long
#define ld long double
#define ull unsigned long long ll
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define si(s) stoi(s)
#define hakuna_mattata                \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ks(n) cout << "Case #" << n + 1 << ": "
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXN 300005
 
using namespace std;
 
int fibonacci(int n){
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    return fibonacci(n-1) + fibonacci(n-2);
}


void solve(ll o)
{
    // inputing value for which fibonacci is required 
    int n; cin >> n;
    cout << fibonacci(n) << endl;
}
 
int main()
{
 
    // freopen("imput.txt","r",stdin);
    // freopen("output.txt","w",stdout);
       
    hakuna_mattata;
 
    // Number of test case   
    ll t = 1;
    cin >> t;
    fr(i, t)
    {
        solve(i);
    }
}
