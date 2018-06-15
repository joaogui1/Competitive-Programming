#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll dp[128][128];
int G[128][128];

ll f(int x, int y){
  if(x == 0 && y == 0)  return 1;
  if(x <= 0 || y <= 0)  return 0;
  if(dp[x][y] != -1)  return dp[x][y];
  dp[x][y] = 0;
  for(int i = x - 1; i > -1; --i)
    for(int j = y - 1; j > -1; --j)
      if(G[x][y] != G[i][j]){
        dp[x][y] += f(i, j);
        dp[x][y] %= MOD;
      }
  return dp[x][y];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  //ifstream cin ("hopscotch.in");
  //ofstream cout ("hopscotch.out");
  int r, c, k;
  cin >> r >> c >> k;
  for(int i = 0; i < r; ++i)
    for(int j = 0; j < c; ++j)
      cin >> G[i][j];
  for(int i = 0; i < 128; ++i)
    for(int j = 0; j < 128; ++j)
      dp[i][j] = -1;
  cout << f(r - 1, c - 1) << "\n";

  return 0;
}
