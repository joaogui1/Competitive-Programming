#include <bits/stdc++.h>

using namespace std;

char dp[128][128];
int rel[128][128], mark[128][128], dx[4] = {0, -1, 1, 0}, dy[4] = {-1, 0, 0, 1}, h, w;

bool lim(int x, int y){
  return (x > -1 && y > -1 && w > x && h > y);
}

char dfs(int x, int y, char op){
  mark[x][y] = 1;
  if(dp[x][y] !=  '-')  return dp[x][y];
  int aux = rel[x][y], idx = -1;
  for(int i = 0; i < 4; ++i)
    if(lim(x + dx[i], y + dy[i]) && rel[x + dx[i]][y + dy[i]] < aux){
      idx = i;
      aux = rel[x + dx[i]][y + dy[i]];
    }
  if(idx == -1) return (dp[x][y] = op);
  return dp[x][y] = dfs(x + dx[idx], y + dy[idx], op);
}

void initialize(){
  for(int i = 0; i < 128; ++i)
    for(int j = 0; j < 128; ++j)
      dp[i][j] = '-';
  memset(rel, 0, sizeof rel);
  memset(mark, 0, sizeof mark);
}

int main(){
  ios_base::sync_with_stdio(0);
  char aux = 'a';
  int n;
  cin >> n;
  for(int t = 1; t <= n; ++t){
    aux = 'a';
    initialize();
    cin >> h >> w;
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        cin >> rel[j][i];

    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        if(!mark[j][i]){
          dfs(j, i, aux);
          if(dfs(j, i, aux) == aux)  ++aux;
        }
    cout << "Case #" << t << ":\n";
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j)
        cout << dp[j][i] << " \n"[j == w - 1];
  }

  return 0;
}
