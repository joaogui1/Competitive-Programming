#include <bits/stdc++.h>

using namespace std;

int dp[2][15001], a[15001], b[15001], v[2][15001], memo[15001];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= m; ++i)
    cin >> b[i];

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j < i; ++j)
      if(a[i] == a[j])  v[0][i] = j;

  for(int i = 1; i <= m; ++i)
    for(int j = 1; j < i; ++j)
      if(b[i] == b[j])  v[1][i] = j;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(a[i] == b[j])
        dp[i%2][j] = max(((v[0][i] && v[1][j])?(2 + memo[v[1][j]]):0), dp[(i - 1)%2][j - 1]);
      else
        dp[i%2][j] = max(dp[(i - 1)%2][j], dp[i%2][j - 1]);
    }
    for(int j = 1; j <= m; ++j)
      if(a[i] == b[j])
        memo[j] = dp[(i - 1)%2][j - 1];
  }
  cout << dp[n%2][m] << "\n";
  return 0;
}
