#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

char res[4] = {'W', 'N', 'E', 'S'};
int G[64][64], id[64][64], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, sz[1 << 16];

int dfs(pii u, int ego){
  pii v;
  id[u.ff][u.ss] = ego;
  for(int i = 0; i < 4; ++i){
    v.ff = u.ff + dx[i], v.ss = u.ss + dy[i];
    if(!(G[u.ff][u.ss] & (1 << i)) && !id[v.ff][v.ss])  ++sz[ego], dfs(v, ego);
  }
  return id[u.ff][u.ss];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii u, v;
  int n, m, ans = 0, cont = 1;
  cin >> n >> m;
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)  cin >> G[j][i];


  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
      if(!id[j][i]) ++ans, sz[cont] = 1, dfs(pii(j, i), cont++);
  cout << ans << "\n";

  ans = -1;
  for(int i = 1; i <= cont; ++i)
      ans = max(ans, sz[i]);
  cout << ans << "\n";

  ans = -1;
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j){
      u = pii(j, i);
      for(int k = 0; k < 4; ++k){
        v.ff = u.ff + dx[k], v.ss = u.ss + dy[k];
        if((G[u.ff][u.ss] & (1 << k)) && id[u.ff][u.ss] != id[v.ff][v.ss])  ans = max(ans, sz[id[u.ff][u.ss]] + sz[id[v.ff][v.ss]]);
      }
    }
  cout << ans << "\n";

  for(int i = m - 1; i > -1; --i)
    for(int j = 0; j < n; ++j){
      u = pii(j, i);
      for(int k = 0; k < 4; ++k){
        v.ff = u.ff + dx[k], v.ss = u.ss + dy[k];
        if((G[u.ff][u.ss] & (1 << k)) && id[u.ff][u.ss] != id[v.ff][v.ss])
          if(sz[id[u.ff][u.ss]] + sz[id[v.ff][v.ss]] == ans){
            cout << u.ss + 1 << " " << u.ff + 1 << " " << res[k] << "\n";
            i = -1;
            j = n + 1;
            break;
          }
      }
    }

  return 0;
}
