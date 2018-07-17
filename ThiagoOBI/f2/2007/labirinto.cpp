#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> pip;

int g[16][64][64], d[16][64][64], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(int n, int m){
  pip u, v;
  queue<pip> q;
  u = pip(0, pii(1, 1));
  d[u.ff][u.ss.ff][u.ss.ss] = 0;
  q.push(u);
  while(q.size()){
    u = q.front();q.pop();
    if(u.ss.ff == n && u.ss.ss == m)  return d[u.ff][u.ss.ff][u.ss.ss];
    v = u;
    v.ff = (u.ff + 1) % 10;
    if(d[v.ff][v.ss.ff][v.ss.ss] == -1){
      d[v.ff][v.ss.ff][v.ss.ss] = 1 + d[u.ff][u.ss.ff][u.ss.ss];
      q.push(v);
    }
    for(int i = 0; i < 4; ++i){
      v = pip((u.ff + 1)%10, pii(u.ss.ff + dx[i], u.ss.ss + dy[i]));
      if(g[u.ff][u.ss.ff][u.ss.ss] + 1 < g[u.ff][v.ss.ff][v.ss.ss]) continue;
      if(d[v.ff][v.ss.ff][v.ss.ss] == -1){
        d[v.ff][v.ss.ff][v.ss.ss] = 1 + d[u.ff][u.ss.ff][u.ss.ss];
        q.push(v);
      }
    }
  }
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  memset(d, -1, sizeof d);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j){
      scanf("%d", &g[0][i][j]);
      for(int k = 1; k < 10; ++k)
        g[k][i][j] = (1 + g[k - 1][i][j])%10;
    }
  for(int i = 0; i <= n + 1; ++i)
    for(int j = 0; j < 10; ++j)
      g[j][i][0] = g[j][i][m + 1] = 16;

  for(int i = 0; i <= m + 1; ++i)
    for(int j = 0; j < 10; ++j)
      g[j][0][i] = g[j][n + 1][i] = 16;

  printf("%d\n", bfs(n, m));

  return 0;
}
