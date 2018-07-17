#include <bits/stdc++.h>

using namespace std;

int dp[2][2001][2001], a[2001], b[2001], v[2][2001];

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

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j){
      if(a[i] == b[j]){
        dp[0][i][j] = max(1 + dp[1][i - 1][j - 1], max(dp[0][i - 1][j], dp[0][i][j - 1]));
        dp[1][i][j] = max(((v[0][i] && v[1][j])?(1 + dp[0][v[0][i]][v[1][j]]):0), dp[1][i - 1][j - 1]);
      }
      else{
        dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]);
        dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j - 1]);
      }
    }
  cout << dp[1][n][m] << "\n";
  return 0;
}
