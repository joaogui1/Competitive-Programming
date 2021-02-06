#include <bits/stdc++.h>

using namespace std;

int g[4][128], n, dp[4][128];
string ans[2] = {"NO", "YES"};

int f(int pos, int t){
  if(pos > 2)  return 0;
  if(t >= n)  return 1;
  if(dp[pos][t] != -1)  return dp[pos][t];
  bool ret = 0;
  if(g[pos][t + 1] == 1)  return ret;
  for(int i = -1; i < 2; ++i)
    if(pos + i > -1 && g[pos + i][t + 1] == 0 && g[pos + i][t + 2] == 0 && g[pos + i][t + 3] == 0){
      ret |= f(pos + i, t + 3);
    }
  // if(ret == 1)  cout << "ok " << pos << " " << t << "\n";
  return dp[pos][t] = ret;
}

void initialize(){
  memset(g, 0, sizeof g);
  memset(dp, -1, sizeof dp);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char auc;
  int t, k, pos;
  cin >> t;
  while(t--){
    initialize();
    cin >> n >> k;
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < n; ++j){
        cin >> auc;
        if(auc >= 'A' && auc <= 'Z')  g[i][j] = 1;
        if(auc == 's')  pos = i;
      }
    cout << ans[f(pos, 0)] << "\n";
    // cout << f(0, 9) << "\n";
  }


  return 0;
}
