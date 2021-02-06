#include <bits/stdc++.h>

using namespace std;

int dp[4][1 << 10][1 << 10], g[1 << 10][1 << 10];

void f(int n, int m){
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(g[i][j]){
        dp[0][i][j] = 1;
        if(g[i][j - 1])
          dp[0][i][j] = dp[0][i - 1][j - 1] + 2;
      }
}

void q(int n, int m){
  for(int i = 1; i <= n; ++i)
    for(int j = m; j > 0; --j)
      if(g[i][j]){
        dp[1][i][j] = 1;
        if(g[i - 1][j])
          dp[1][i][j] = dp[1][i - 1][j + 1] + 2;
      }
}

void h(int n, int m){
  for(int i = n; i > 0; --i)
    for(int j = 1; j <= m; ++j)
      if(g[i][j]){
        dp[2][i][j] = 1;
        if(g[i + 1][j])
          dp[2][i][j] = dp[2][i + 1][j - 1] + 2;
      }
}

void l(int n, int m){
  for(int i = n; i > 0; --i)
    for(int j = m; j > 0; --j)
      if(g[i][j]){
        dp[3][i][j] = 1;
        if(g[i][j + 1])
          dp[3][i][j] = dp[3][i + 1][j + 1] + 2;
      }
}

void initialize(){
  memset(g, 0, sizeof g);
  memset(dp, 0, sizeof dp);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t, n, m, best = 0, test = 0;
  string aux;
  cin >> t;
  while(t--){
    best = 0;
    cin >> n >> m;
    initialize();
    for(int i = 1; i <= n; ++i){
      cin >> aux;
      for(int j = 1; j <= m; ++j)
        g[i][j] = (aux[j - 1] == '1');
    }

    f(n, m);
    q(n, m);
    l(n, m);
    h(n, m);

    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j){
        test = 0;
        for(int k = 0; k < 4; ++k)  test += dp[k][i][j];
        test = max(0, test - 3);  
        best = max(best, test);
      }
    cout << best << "\n";
  }


  return 0;
}
