#include "bits/stdc++.h"
using namespace std;

int Solution::maxProfit(const vector<int> &A)
{
   if (A.size() == 0)
      return 0;
   int min = A[0];
   int sum = 0;
   for (int i = 1; i < A.size(); i++)
   {
      if (A[i] < min)
      {
         min = A[i];
      }
      if (A[i] > min)
      {
         sum = sum + A[i] - min;
         min = A[i];
      }
   }
   return sum;
}