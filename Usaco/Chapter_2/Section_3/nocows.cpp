/*
ID: joaogui1
LANG: C++
TASK: nocows
*/
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define max(a, b) a>b?a:b
using namespace std;
long long int dp[300][300];
long long int f(long long int n, long long int k){
   if(dp[n][k] != -1)   return dp[n][k];
   if(n == 1 && k == 1) return dp[n][k] = 1;
   if(n == 0 && k == 0) return dp[n][k] = 1;
   if(n%2 == 0)   return dp[n][k] = 0;
   if(n < 2*k - 1)   return dp[n][k] = 0;
   if(k == 0)  return dp[n][k] = 0;
   int ret = 0;
   for(int a = 1; a < n-1; ++a)
      for(int i = 1; i < k - 1; ++i){
         ret += f(n - a - 1, k - 1)*f(a, i);
         ret %= 9901;
      }
      ret*=2;ret%=9901;
      for(int a = 1; a < n - 1; ++a){
         ret += f(n - a - 1, k - 1)*f(a, k - 1);
         ret %=9901;
      }
   return dp[n][k] = ret;
}
int main(){
   long long int ans, n, k;
   ifstream fin ("nocows.in");
   ofstream fout ("nocows.out");
   fin >> n >> k;
   memset(dp, -1, sizeof(dp));
   ans += f(n, k);
   fout << ans << endl;

   return 0;
}
