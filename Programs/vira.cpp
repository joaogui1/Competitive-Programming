#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

bool v[1001];
int dp[2][1001][2];


int main(){
  //ios_base::sync_with_stdio(0);
  int n;
  char op;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf(" %c", &op);
    v[i + 1] = (op == 'P');
  }
  dp[1][1][1] = 1;
  for(int i = 2; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      dp[(i & 1)][j][0] = dp[((i - 1) & 1)][j - 1][v[i - 1]];
      dp[(i & 1)][j][1] = dp[((i - 1) & 1)][i - 1][!v[i - 1]] - dp[((i - 1) & 1)][j - 1][!v[i - 1]];
      if(dp[(i & 1)][j][1] < 0) dp[(i & 1)][j][1] += MOD;
      if(dp[(i & 1)][j][1] >= MOD)  dp[(i & 1)][j][1] %= MOD;
      dp[(i & 1)][j][0] += dp[(i & 1)][j - 1][0];
      if(dp[(i & 1)][j][0] >= MOD)  dp[(i & 1)][j][0] %= MOD;
      dp[(i & 1)][j][1] += dp[(i & 1)][j - 1][1];
      if(dp[(i & 1)][j][1] >= MOD)  dp[(i & 1)][j][1] %= MOD;
    }

  }
  //for(int i = 0; i < n; ++i)  ans += dp[n][i][v[n]];
  printf("%d\n", dp[n & 1][n][v[n]]);
  return 0;
}
