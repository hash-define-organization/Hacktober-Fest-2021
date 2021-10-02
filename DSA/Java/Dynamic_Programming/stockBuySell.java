import java.io.*;
 
class GFG
{
 
    static int maxProfit(int prices[], int size)
    {
       
        // maxProfit adds up the difference between
        // adjacent elements if they are in increaisng order
        int maxProfit = 0;
       
        // The loop starts from 1
        // as its comparing with the previous
        for (int i = 1; i < size; i++)
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        return maxProfit;
    }
   
  // Driver code
    public static void main(String[] args)
    {
       
        // stock prices on consecutive days
        int price[] = { 100, 180, 260, 310, 40, 535, 695 };
        int n = price.length;
 
        // function call
        System.out.println(maxProfit(price, n));
    }
}
