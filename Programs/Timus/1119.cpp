#include <bits/stdc++.h>

using namespace std;

int mark[1024][1024];
double dp[1024][1024];

double f(int i, int j){
  if(i < 0 || j < 0)  return (1 << 20);
  if(i == 0 && j == 0)  return 0;
  if(dp[i][j] != 0) return dp[i][j];
  dp[i][j] = 100 + min(f(i - 1, j), f(i, j - 1));
  if(mark[i][j])  dp[i][j] = min(dp[i][j], 100*sqrt(2) + f(i - 1, j - 1));
  return dp[i][j];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, k, x, y;
  cin >> n >> m >> k;
  for(int i = 0; i < k; ++i){
    cin >> x >> y;
    ++mark[x][y];
  }
  cout << fixed << setprecision(0) << f(n, m) << "\n";
  return 0;
}
