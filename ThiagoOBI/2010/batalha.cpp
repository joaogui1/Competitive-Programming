#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int id[128][128], G[128][128], ship[128*128], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void dfs(pii pos, int color){
  ++ship[color];
  id[pos.ff][pos.ss] = color;
  for(int i = 0; i < 4; ++i)
    if(G[pos.ff + dx[i]][pos.ss + dy[i]] && id[pos.ff + dx[i]][pos.ss + dy[i]] == -1)
      dfs(pii(pos.ff + dx[i], pos.ss + dy[i]), color);
  return;
}

int main(){
  pii pos;
  string s;
  int n, m, cid = 0, k, ans = 0;
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; ++i){
    cin >> s;
    for(int j = 0; j < m; ++j)
      G[i][j] = (s[j] == '#');
  }
  memset(id, -1, sizeof id);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(id[i][j] == -1 && G[i][j])
        dfs(pii(i, j), cid++);


  scanf("%d", &k);
  for(int i = 0; i < k; ++i){
    scanf("%d %d", &pos.ff, &pos.ss);
    --pos.ff, --pos.ss;
    if(id[pos.ff][pos.ss] != -1)
      --ship[id[pos.ff][pos.ss]];

  }
  for(int i = 0; i < cid; ++i)  ans += (ship[i] < 1);

  printf("%d\n", ans);
  return 0;
}
