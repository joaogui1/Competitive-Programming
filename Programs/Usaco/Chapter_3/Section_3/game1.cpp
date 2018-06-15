/*
ID: joaogui1
LANG: C++
TASK: game1
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int c[120], dp[120][120];
int main(){
   ios_base::sync_with_stdio(0);
   int n, sum = 0;
   ifstream fin ("game1.in");
   ofstream fout ("game1.out");
   fin >> n;
   for(int i = 1; i <= n; ++i)   fin >> c[i];
   for(int i = 1; i <= n; ++i)   sum += c[i];
   for(int j = 1; j <= n; ++j)
      for(int i = j; i > 0; --i){
         if(i == j)  dp[i][j] = c[i];
         if(i + 1 == j) dp[i][j] = max(c[i], c[j]);
         else  dp[i][j] = max(c[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), c[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
      }
   fout << dp[1][n] << " " << sum - dp[1][n] << "\n";

   return 0;
}
