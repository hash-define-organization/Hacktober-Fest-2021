#include <bits/stdc++.h>

#define MAXN 100000  
using namespace std;
 
long long fibonacci[MAXN+5];

void pre_computation(){
    // pre computing all the fibonacci values
    fibonacci[1] = 1;
    for(int i=2;i<=MAXN;i++){
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
    }
}

void solve(int i)
{
    // inputing value for which fibonacci is required 
    int number; cin >> number;
    cout << fibonacci[number] << endl;
}
 
int main()
{

    pre_computation();
    int test_cases = 1;
    cin >> test_cases;
    for(int i=0;i<test_cases;i++)
    {
        solve(i);
    }
}
