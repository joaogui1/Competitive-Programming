#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int g[64][64], c[64][64], cnt = 1;

void init(int r, int c, int sr, int sc, int m, char* s){
  for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j)
      g[i][j] = 1;
  g[sr][sc] = 0;
  for(int i = 0; i < m; ++i){
    if(s[i] == 'N') --sr;
    if(s[i] == 'S') ++sr;
    if(s[i] == 'E') ++sc;
    if(s[i] == 'W') --sc;
    g[sr][sc] = 0;
  }

}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(pii u, int co){
  pii v;
  c[u.ff][u.ss] = co;
  for(int i = 0; i < 4; ++i){
    v.ff = u.ff + dx[i], v.ss = u.ss + dy[i];
    if(c[v.ff][v.ss] != co && g[v.ff][v.ss])  dfs(v, co);
  }
}

int colour(int ar, int ac, int br, int bc){
  int ans = 0;
  for(int i = ar; i <= br; ++i)  c[i][ac - 1] = c[i][bc + 1] = cnt;
  for(int i = ac; i <= bc; ++i)  c[ar - 1][i] = c[br + 1][i] = cnt;

  for(int i = ar; i <= br; ++i)
    for(int j = ac; j <= bc; ++j)
      if(c[i][j] != cnt && g[i][j])
        dfs(pii(i, j), cnt), ++ans;
  ++cnt;
  return ans;
}
