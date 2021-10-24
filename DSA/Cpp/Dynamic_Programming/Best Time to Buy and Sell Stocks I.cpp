#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A)
{
   int minVal = INT_MAX;
   int maxProfit = 0;

   for (int i = 0; i < A.size(); i++)
   {
      if (A[i] < minVal)
         minVal = A[i];
      else
      {
         maxProfit = max(maxProfit, A[i] - minVal);
      }
   }
   return maxProfit;
}
