#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int v[1024], dp[1024][1024][2], sum[1024][1024][2];


int main(){
  int n;
  char op;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf(" %c", &op);
    v[i] = (op == 'P');
  }
  dp[1][1][1] = sum[1][1][1] = 1;

  for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= i; ++j){
      // for(int k = 1; k < j; ++k)
      //   dp[i][j][0] += dp[i - 1][k][v[i - 1]];
      dp[i][j][0] = sum[i - 1][j - 1][v[i - 1]];
      sum[i][j][0] = (sum[i][j - 1][0] + dp[i][j][0])%MOD;
      // for(int k = j; k < i; ++k)
      //   dp[i][j][1] += dp[i - 1][k][!v[i - 1]];
      dp[i][j][1] = sum[i - 1][i - 1][!v[i - 1]] - sum[i - 1][j - 1][!v[i - 1]];
      dp[i][j][1] = ((dp[i][j][1])%MOD + MOD)%MOD;
      sum[i][j][1] = (sum[i][j - 1][1] + dp[i][j][1])%MOD;
    }

  // for(int i = 1; i <= n; ++i) ans += dp[n][i][v[n]];
  // cout << ans << "\n";
  cout << sum[n][n][v[n]] << "\n";
  return 0;
}
