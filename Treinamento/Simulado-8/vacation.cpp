#include <bits/stdc++.h>

using namespace std;

int temp[60], n, k, dp[60][(1 << 20)];

int go(int pos, int mask){
  if(pos == 3*n)  return 0;
  if(dp[pos][mask] != -1)  return dp[pos][mask];
  int shadow = mask;
  if(pos >= n) shadow >>= 1;
  if(__builtin_popcount(shadow) < k)  dp[pos][mask] = temp[pos] + go(pos + 1, shadow + (1 << min((n - 1), pos)));
  dp[pos][mask] = max(dp[pos][mask], go(pos + 1, shadow));
  return dp[pos][mask];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int aux, sum = 0, ans = 0;
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < 3*n; ++i)  cin >> temp[i];

  cout << go(0, 0) << "\n";


  return 0;
}
