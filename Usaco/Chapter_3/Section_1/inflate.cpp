/*
ID: joaogui1
LANG: C++
TASK: inflate
*/
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[10010];
int main(){
   int n, m, auc, aut;
   ifstream fin ("inflate.in");
   ofstream fout ("inflate.out");
   fin >> m >> n;
   for(int i = 1; i <= n; ++i){
      fin >> auc >> aut;
      for(int j = aut; j <= m; ++j)
         dp[j] = max(dp[j], dp[j - aut] + auc);
   }
   fout << dp[m] << endl;
   return 0;
}
