#include <bits/stdc++.h>
#define INF (1 << 27)

using namespace std;

int dp[32][128], n;
vector<int> cloth[32];

int f(int idx, int m){
  if(dp[idx][m] != -1)  return dp[idx][m];
  if(m < 0) return -INF;
  if(idx >= n)  return 0;
  dp[idx][m] = -INF;
  for(int i = 0; i < cloth[idx].size(); ++i)
    dp[idx][m] = max(dp[idx][m], cloth[idx][i] + f(idx + 1, m - cloth[idx][i]));

  return dp[idx][m];
}

int main(){
  ios_base::sync_with_stdio(0);
  int T, c, k, a;
  cin >> T;
  while(T--){
    cin >> c >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i){
      cin >> k;
      cloth[i].assign(k, 0);
      for(int j = 0; j < k; ++j)  cin >> cloth[i][j];
    }
    if(f(0, c) > 0) cout << f(0, c) << "\n";
    else  cout << "no solution\n";
  }

  return 0;
}
