#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

map <string, int> dict;
int g[64][64], G[64][64], dist[4][64][64], dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0};

void initialize(){
  memset(g, 0, sizeof g);
  memset(G, 0, sizeof G);
  memset(dist, -1, sizeof dist);
}

void bfs(int x, int y, int pos){
  ppi u, v;
  dist[pos][x][y] = 0;
  queue<ppi> q;
  q.push(ppi(pii(x, y), pos));
  while(q.size()){
    u = q.front();q.pop();
    v.ss = u.ss;
    v.ff.ff = u.ff.ff + dx[u.ss];
    v.ff.ss = u.ff.ss + dy[u.ss];
    if(dist[v.ss][v.ff.ff][v.ff.ss] == -1 && G[v.ff.ff][v.ff.ss] != 0){
      q.push(v);
      dist[v.ss][v.ff.ff][v.ff.ss] = 1 + dist[u.ss][u.ff.ff][u.ff.ss];
    }
    v = u;
    v.ss = (u.ss + 1)%4;
    if(dist[v.ss][v.ff.ff][v.ff.ss] == -1 && G[v.ff.ff][v.ff.ss] != 0){
      q.push(v);
      dist[v.ss][v.ff.ff][v.ff.ss] = 1 + dist[u.ss][u.ff.ff][u.ff.ss];
    }
    v.ss = (u.ss + 3)%4;
    if(dist[v.ss][v.ff.ff][v.ff.ss] == -1 && G[v.ff.ff][v.ff.ss] != 0){
      q.push(v);
      dist[v.ss][v.ff.ff][v.ff.ss] = 1 + dist[u.ss][u.ff.ff][u.ff.ss];
    }
  }
}

int main(){
  dict["north"] = 0;
  dict["west"] = 1;
  dict["south"] = 2;
  dict["east"] = 3;
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, bx, by, ex, ey, ans;
  string dir;
  while(1){
    ans = -1;
    initialize();
    cin >> n >> m;
    if(n + m == 0)  return 0;

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        cin >> g[i][j];

    for(int i = 0; i < n - 1; ++i)
      for(int j = 1; j < m; ++j)
        G[i][j] = !(g[i][j] || g[i + 1][j] || g[i][j - 1] || g[i + 1][j - 1]);

    cin >> bx >> by >> ex >> ey >> dir;
    bfs(by, bx, dict[dir]);
    for(int i = 0; i < 4; ++i)
      if(ans != -1)
        ans = min(ans, dist[i][ey][ex]);
      else
        ans = dist[i][ey][ex];
    cout << ans << "\n";
  }


  return 0;
}
