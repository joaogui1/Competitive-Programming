#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

int G[128][128], mark[128][128], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void dfs(pii u, int c){
  pii v;
  mark[u.ff][u.ss] = c;
  for(int i = 0; i < 4; ++i){
    v.ff = u.ff + dx[i], v.ss = u.ss + dy[i];
    if(mark[v.ff][v.ss] == -1 && G[u.ff][u.ss] == G[v.ff][v.ss]) dfs(v, c);
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, comp = 0, ans = 5;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> G[i][j];
  memset(mark, -1, sizeof mark);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(mark[i][j] == -1)
        dfs(pii(i, j), comp++);

  ans += comp;
  for(int i = 1; i < n; ++i)
    for(int j = 1; j <= m; ++j)
      if(G[i][j] < G[i + 1][j]){
        if(G[i][j - 1] >= G[i + 1][j - 1])  ++ans;
        else if(G[i + 1][j] <= G[i][j - 1] || G[i + 1][j - 1] <= G[i][j])  ++ans;
      }

  for(int i = n; i > 1; --i)
    for(int j = 1; j <= m; ++j)
      if(G[i][j] < G[i - 1][j]){
        if(G[i][j - 1] >= G[i - 1][j - 1])  ++ans;
        else if(G[i - 1][j] <= G[i][j - 1] || G[i - 1][j - 1] <= G[i][j])  ++ans;
      }

  for(int j = 1; j < m; ++j)
    for(int i = 1; i <= n; ++i)
      if(G[i][j] < G[i][j + 1]){
        if(G[i - 1][j] >= G[i - 1][j + 1])  ++ans;
        else if(G[i][j + 1] <= G[i - 1][j] || G[i - 1][j + 1] <= G[i][j])  ++ans;
      }

  for(int j = m; j > 1; --j)
    for(int i = 1; i <= n; ++i)
      if(G[i][j] < G[i][j - 1]){
        if(G[i - 1][j] >= G[i - 1][j - 1])  ++ans;
        else if(G[i][j - 1] <= G[i - 1][j] || G[i - 1][j - 1] <= G[i][j])  ++ans;
      }

  cout << ans << "\n";

  return 0;
}
