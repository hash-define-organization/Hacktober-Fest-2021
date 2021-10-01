#include <bits/stdc++.h>
  
using namespace std;
 
int fibonacci(int number){
    if(number == 0){return 0;}
    if(number == 1){return 1;}
    return fibonacci(number-1) + fibonacci(number-2);
}


void solve(int i)
{
    // inputing value for which fibonacci is required 
    int number; cin >> number;
    cout << fibonacci(number) << endl;
}
 
int main()
{
 
    int test_cases = 1;
    cin >> test_cases;
    for(int i=0;i<test_cases;i++)
    {
        solve(i);
    }
}
