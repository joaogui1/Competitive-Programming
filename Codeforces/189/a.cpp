#include <bits/stdc++.h>

using namespace std;

int dp[4010];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b, c, ans, aux;
  cin >> n >> a >> b >> c;
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
    if(i >= a && dp[i - a] != -1) dp[i] = max(dp[i], 1 + dp[i - a]);
    if(i >= b && dp[i - b] != -1) dp[i] = max(dp[i], 1 + dp[i - b]);
    if(i >= c && dp[i - c] != -1) dp[i] = max(dp[i], 1 + dp[i - c]);
  }
  cout << dp[n] << "\n";

  return 0;
}
