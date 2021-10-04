class Solution {
public:
    int reverse(int x) {
      
        long int ans = 0;
        //taking digits from back 1 by 1 and adding them in answer 
        while(x != 0)               
        {
            ans = (ans * 10) + (x % 10);
            x = x/10;
        }
      
        if(ans > INT_MAX || ans < INT_MIN)  // to check if there is overflow after the number is reversed
        {
            return 0;
        }
      
      return ans; 
    }
};
