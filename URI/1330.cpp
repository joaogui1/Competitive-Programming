#include <bits/stdc++.h>

using namespace std;

vector <int> adj[64];
int lake[110][110], id[110][110], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, cor[64], m[64], ans, cont;

int arg(int u){
  int v;
  if(cor[u])  return 0;
  cor[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!m[v] || arg(m[v])){
      m[v] = u;
      return 1;
    }
  }
  return 0;
}

void initialize(){
  ans = 0;
  cont = 1;
  memset(m, 0, sizeof m);
  memset(id, -1, sizeof id);
  memset(lake, 0, sizeof lake);
  for(int i = 0; i < 64; ++i) adj[i].clear();
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, k, x, y;
  while(cin >> n >> m){
    initialize();
    if(n == 0 && m == 0)  return 0;
    cin >> k;
    for(int i = 0; i < k; ++i){
      cin >> x >> y;
      lake[x][y] = 1;
    }

    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j)
        if(!lake[i][j])
          id[i][j] = cont++;

    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j)
        for(int kk = 0; kk < 4; ++kk){
          if(id[i + dx[kk]][j + dy[kk]] != -1 && id[i][j] != -1)
            adj[id[i][j]].push_back(id[i + dx[kk]][j + dy[kk]]);
        }

    for(int i = 1; i <= n; ++i)
      for(int j = 1 + !(i&1); j <= m; j += 2){
        if(id[i][j] != -1){
          memset(cor, 0, sizeof cor);
          ans += arg(id[i][j]);
        }
      }
    cout << ans << "\n";
  }



  return 0;
}
