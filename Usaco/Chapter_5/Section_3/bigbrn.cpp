/*
ID: joaogui1
LANG: C++
TASK: bigbrn
*/
#include <bits/stdc++.h>

using namespace std;

int dp[1024][1024];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("bigbrn.in");
  ofstream fout ("bigbrn.out");
  int n, t, a, b, ans = 0;
  fin >> n >> t;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      dp[i][j] = 1;
  for(int i = 1; i <= t; ++i){
      fin >> a >> b;
      dp[a][b] = 0;
    }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
      if(dp[i][j] != 0){
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        ++dp[i][j];
      }
      ans = max(ans, dp[i][j]);
    }

  fout << ans << "\n";

  return 0;
}
