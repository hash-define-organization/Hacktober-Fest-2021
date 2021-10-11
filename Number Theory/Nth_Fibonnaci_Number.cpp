// Problem : Program to find last digit of n’th fibonaccionnaci Number

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fibonacci(ll f[], ll n)
{

	f[0] = 0;
	f[1] = 1;

	for (ll i = 2; i <= n; i++)
		f[i] = (f[i - 1] + f[i - 2]) % 10;

	return f[n];
}

int findLastDigit(int n)
{
	ll f[60] = {0};

	fibonacci(f, 60);

	return f[n % 60];
}

int main()
{
	ll n;
	cout << "Enter the no : ";
	cin >> n;
	cout << findLastDigit(n) << endl;

	return 0;
}
