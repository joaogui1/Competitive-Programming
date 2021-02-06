#include <bits/stdc++.h>

using namespace std;

int dp[32][32];
string dict[1024], in;

void dist(string &a, string &b){
  int v = 0;
  for(int i = 0; i <= a.size(); ++i)  dp[i][0] = i;
  for(int i = 0; i <= b.size(); ++i)  dp[0][i] = i;
  for(int i = 1; i <= a.size(); ++i)
    for(int j = 1; j <= b.size(); ++j)
      if(a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> dict[i];
  for(int i = 0; i < m; ++i){
    cin >> in;
    for(int j = 0; j < n; ++j){
      memset(dp, 0, sizeof dp);
      dist(in, dict[j]);
      if(dp[in.size()][dict[j].size()] <= 2)  cout << dict[j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
