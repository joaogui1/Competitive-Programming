#include <bits/stdc++.h>

using namespace std;

int dp[4][1024][1024], G[1024][1024], dx[3] = {0, -1, 0}, dy[3] = {-1, 0, 1}, n, m;

int f(int dir, int x, int y){
  if(x == 0 && y == 0)  return G[x][y];
  if(x < 0 || y < 0 || y == m)  return -(1 << 28);
  if(dp[dir][x][y] != -1) return dp[dir][x][y];
  dp[dir][x][y] = f(1, x + dx[dir], y + dy[dir]);
  if(dir != 0)  dp[dir][x][y] = max(dp[dir][x][y], f(2, x + dx[dir], y + dy[dir]));
  if(dir != 2)  dp[dir][x][y] = max(dp[dir][x][y], f(0, x + dx[dir], y + dy[dir]));
  dp[dir][x][y] += G[x][y];
  return dp[dir][x][y];
}

int f(int x, int y){
  return max(f(0, x, y), max(f(1, x, y), f(2, x, y)));
}

int main(){
  for(int t = 1; scanf("%d %d", &n, &m); ++t){
    if(n + m == 0)  return 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        scanf("%d", &G[i][j]);
    printf("Teste %d\n%d\n\n", t, f(n - 1, m - 1));


  }


  return 0;
}
