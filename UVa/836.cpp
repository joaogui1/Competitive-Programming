#include <bits/stdc++.h>

using namespace std;

int dp[32][32], best, n;
string G[32];

void initialize(){
  n = 0;
  best = 0;
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < 32; ++i) G[i].clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, test;
  string aux;
  cin >> t;
  getline(cin, aux);
  getline(cin, aux);
  for(int q = 0; q < t; ++q){
    initialize();
    while(1){
      getline(cin, aux);
      if(aux.size() == 0) break;
      G[n++] = aux;
    }

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j){
        dp[i][j] = (G[i][j] - '0');
        if(i > 0) dp[i][j] += dp[i - 1][j];
        if(j > 0) dp[i][j] += dp[i][j - 1];
        if(i > 0 && j > 0)  dp[i][j] -= dp[i - 1][j - 1];
      }

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        for(int k = i; k < n; ++k)
          for(int l = j; l < n; ++l){
            test = dp[k][l];
            if(i > 0) test -= dp[i - 1][l];
            if(j > 0) test -= dp[k][j - 1];
            if(i > 0 && j > 0)  test += dp[i - 1][j - 1];
            if(test == (k - i + 1)*(l - j + 1)) best = max(best, test);
          }
    if(q > 0) cout << "\n";
    cout << best << "\n";
  }



  return 0;
}
