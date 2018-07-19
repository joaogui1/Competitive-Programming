#include <bits/stdc++.h>

using namespace std;

int mat[210][210], dp[210][210];

int sqr(int n, int m){
  int ret = 0;
  for(int i = 0; i < n; ++i)  dp[i][0] = mat[i][0];
  for(int i = 1; i < m; ++i)  dp[0][i] = mat[0][i];

  for(int i = 1; i < n; ++i)
    for(int j = 1; j < m; ++j){
      if(mat[i][j] == 1) dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
      else  dp[i][j] = 0;
      ret = max(ret, dp[i][j]);
    }
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char auc;
  int n, m, k, x, y;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
      cin >> auc;
      if(auc == '.')  mat[i][j] = 1;
    }
  for(int i = 0; i < k; ++i){
    cin >> x >> y;
    mat[x - 1][y - 1] = 0;
    cout << sqr(n, m) << "\n";
  }


  return 0;
}
