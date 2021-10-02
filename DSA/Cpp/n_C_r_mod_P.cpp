#include <bits/stdc++.h>
using namespace std;

void solve()
{ 
    int n,r;
    cin>>n>>r;
    
  const int mod=1e9+7;
  int C[r+1];
  memset(C,0,sizeof(C));
  C[0]=1;
  for(int i=0;i<=n;i++)
  {
      for(int j=min(i,r);j>0;j--)
      {
          C[j]=(C[j]+C[j-1])%mod;
      }
  }
  if(!C[r])
  cout<<C[r]<<endl;
  else 
  cout<<0<<endl;
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