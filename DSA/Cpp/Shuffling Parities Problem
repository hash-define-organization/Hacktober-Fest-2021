Here's the solution: 

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N, e=0, o=0;
	    cin>>N;
	    int a[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>a[i];
	        if(a[i]%2==0)
	        {
	            e++;
	        }
	        else
	        {
	            o++;
	        }
	    }
	    int to,te;
	    if(N%2==1)
	    {
	        to=(N+1)/2;
	        te=N/2;
	    }
	    else
	    {
	        to=N/2;
	        te=N/2;
	    }
	    int sum=0;
	    if(o==te && e==to)
	    {
	        sum=o+e;
	    }
	    else if(o<te && e>to)
	    {
	        sum=o+to;
	    }
	    else if(e<to && o>te)
	    {
	        sum=e+te;
	    }
	    
	    cout<<sum<<endl;
	}
	return 0;
}
