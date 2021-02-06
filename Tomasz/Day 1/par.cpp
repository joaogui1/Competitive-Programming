#include <bits/stdc++.h>

using namespace std;

int g[1 << 10][1 << 10], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, dp[1 << 10][1 << 10];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  char op;
  cin >> n;
  for(int i = 10; i <= n + 9; ++i)
    for(int j = 10; j <= n + 9; ++j){
      cin >> op;
      g[i][j] = (op == 'B');
    }

  for(int i = 10; i <= n + 9; ++i){
    for(int j = 10; j <= n + 9; ++j){
      for(int k = 0; k < 4; ++k)
        for(int l = 0; l < 4; ++l)
          dp[i][j] |= g[i + dx[k] + dx[l]][j + dy[k] + dy[l]];
      if(dp[i][j] > 0)  continue;
      for(int k = 0; k < 4; ++k)
        for(int l = 0; l < 4; ++l)
          for(int m = 0; m < 4; ++m)
            dp[i][j] |= g[i + dx[k] + dx[l] + dx[m]][j + dy[k] + dy[l] + dy[m]];
    }
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      ans = max(ans, dp[i][j]);
  ans = min(ans, 2);
  cout << ans + 3 << "\n";
  return 0;
}
