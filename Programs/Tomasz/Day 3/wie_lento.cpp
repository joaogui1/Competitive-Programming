#include <bits/stdc++.h>
#define oo (1 << 28);

using namespace std;

int dp[2012][2012], t[2012];

int f(int i, int j){
  if(i + 1 >= j)  return 0;
  if(i + 2 == j)  return t[i + 1];
  if(dp[i][j] != -1)  return dp[i][j];
  dp[i][j] = oo;

  for(int k = i + 1; k < j; ++k){
    if(t[k] < dp[i][j]) dp[i][j] = min(dp[i][j], t[k] + max(f(i, k), f(k, j)));
  }
  return dp[i][j];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  for(int i = 1; i <= n; ++i) cin >> t[i];

  cout << f(0, n + 1) << "\n";
  return 0;
}
