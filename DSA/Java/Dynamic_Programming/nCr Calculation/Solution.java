class Solution
{
    
    static int p = 1000000007;
    
    public static int min(int a, int b) 
    { 
        return (a<b)? a: b;  
    }
    
    //Function to return nCr mod 10^9+7 for given n and r.
    public static int nCrModp(int n, int r)
    {
        //array C[] is going to store last row of pascal triangle at the end.
        //last entry of last row is nCr. 
        int C[] = new int[r+1];
        Arrays.fill(C, 0);
    
        //top row of Pascal Triangle 
        C[0] = 1; 
    
        //one by one constructing remaining rows of Pascal 
        //triangle from top to bottom.    
        for (int i = 1; i <= n; i++) 
        { 
          //filling entries of current row using previous row values. 
          for (int j = min(i, r); j > 0; j--) 
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j]%p + C[j-1]%p)%p; 
        } 
        
        //returning the result.
        return C[r];
    }
}
