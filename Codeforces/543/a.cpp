#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll dp[4][512][512], v[512], mod, n;

// ll f(ll m, ll b, ll x){
//   if(b < 0 || x == 0) return 0;
//   if(m == 0 && b == 0)  return 1;
//   if(dp[m][b][x] != -1)  return dp[m][b][x];
//   dp[m][b][x] = f(m, b, x - 1) + f(m - 1, b - v[x], x);
//   dp[m][b][x] %= mod;
//   return dp[m][b][x];
// }

ll f(ll m, ll b){
  for(int i = 1; i <= n; ++i) dp[0][0][i] = 1;
  for(int i = 1; i <= m; ++i)
    for(int j = 0; j <= b; ++j)
      for(int k = 1; k <= n; ++k){
        dp[(i&1)][j][k] = dp[(i&1)][j][k - 1];
        if(j >= v[k]) dp[(i&1)][j][k] += dp[(i + 1)&1][j - v[k]][k];
        if(dp[(i&1)][j][k] > 1000000000)  (dp[(i&1)][j][k]) %= mod;
      }
    ll ans = 0;
    for(int i = 0; i <= b; ++i){
        ans += dp[(m&1)][i][n];
        if(ans > 1000000000)  ans %= mod;
      }
    return (ans%mod);
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  ll m, b;
  cin >> n >> m >> b >> mod;
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; ++i) cin >> v[i];

  cout << f(m, b) << "\n";
  return 0;
}
