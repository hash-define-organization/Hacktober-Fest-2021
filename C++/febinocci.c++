#include<iostream>
using namespace std;
 
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
 
int main ()
{
    int n ;
    cout<<"Enter number Of Turms :";
    cin>>n;
    cout << "Result is " <<fib(n)<<"\n";
    return 0;
}