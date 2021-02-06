/*
ID: joaogui1
LANG: C++
TASK: subset
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define entre(a, b, c) (a <= b && b <= c)
using namespace std;
long long int dp[50*50][50];
long long int f(long int n, long int k){
   if(n < 0 || k < 0)   return 0;
   if(dp[n][k] != -1) return dp[n][k];
   if(n == 0 && k == 0) return dp[0][0] = 1;
   return dp[n][k] = f(n, k-1) + f(n-k , k - 1);
}
int main(){
   long long int n, tot_sum, ans;
   ifstream fin ("subset.in");
   ofstream fout ("subset.out");
   fin >> n;
   memset(dp, -1, sizeof(dp));
   if(n*(n + 1) % 4 != 0)  fout << 0 << endl;
   else{
      tot_sum = (n*(n+1))/4;
      ans = f(tot_sum, n);
      fout << ans/2 << endl;
   }
   return 0;
}
