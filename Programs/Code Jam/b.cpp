#include <bits/stdc++.h>

using namespace std;

int dp[16][16][1 << 11], bf[16], n;
vector <int> fb[16];

int f(int i, int j, int used){
  if(dp[i][j][used] != -1)  return dp[i][j][used];
  if((used & (used + 1)) == 0 && used > (1 << (n - 1))){
      cout << i << " " << j << " " << bitset<4>(used) << endl;
      return 1; //todo preenchido
  }

  int bi, bj;
  dp[i][j][used] = 0;

  bi = bf[i];
  if(!((1 << (bi - 1)) & used)) dp[i][j][used] = max(dp[i][j][used], 1 + f(bi, j, used | (1 << (bi - 1))));
  for(int k = 0; k < fb[i].size(); ++k){
    bi = fb[i][k];
    if(!((1 << (bi - 1)) & used)) dp[i][j][used] = max(dp[i][j][used], 1 + f(bi, j, used | (1 << (bi - 1))));
  }


  bj = bf[j];
  if(!((1 << (bj - 1)) & used)) dp[i][j][used] = max(dp[i][j][used], 1 + f(i, bj, used | (1 << (bj - 1))));
  for(int k = 0; k < fb[j].size(); ++k){
    bj = fb[j][k];
    if(!((1 << (bj - 1)) & used)) dp[i][j][used] = max(dp[i][j][used], 1 + f(i, bj, used | (1 << (bj - 1))));
  }
  cout << i << " " << j << " " << bitset<4>(used) << " " << dp[i][j][used] << endl;
  return dp[i][j][used];
}

int f(){
  int ret = 0;
  for(int i = 1; i <= n; ++i)
    ret = max(ret, f(i, i, 1 << (i - 1)));
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; ++i){
      cin >> bf[i];
      fb[bf[i]].push_back(i);
    }
    cout << f() << "\n";
  }

  return 0;
}
