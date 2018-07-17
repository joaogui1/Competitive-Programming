#include <bits/stdc++.h>

using namespace std;

set <int> resp;
vector <int> in[1000010];
int sz[1000010], nx[1000010], mark[1000010], era[1000010], id[1000010], intrsz[1000010];

bool has_cycle(int s, int u){
  mark[u] = 1;
  if(nx[u] == s)  return 1;
  if(nx[u] != u && !mark[nx[u]])  return has_cycle(s, nx[u]);
  return 0;
}

void paint(int c, int u){
  id[u] = c;
  for(int i = 0; i < in[u].size(); ++i)
    nx[in[u][i]] = c;
  if(id[nx[u]] != c)  paint(c, nx[u]);
}

void dfs(int u){
  sz[u] = intrsz[u];
  if(era[u])  return;
  if(sz[nx[u]] == 0 && !era[nx[u]])  dfs(nx[u]);
  if(mark[nx[u]] && u != nx[u] && !era[nx[u]]) sz[u] += sz[nx[u]];
  mark[u] = 1;
  return;
}

void Erase(int u){
  mark[u] = 1;
  if(nx[u] != u && mark[nx[u]] == 0)  Erase(nx[u]);
  for(int i = 0; i < in[u].size(); ++i)
    nx[in[u][i]] = in[u][i];
  sz[u] = 0;
  nx[u] = u;
  era[u] = 1;
}
void initialize(int n){
  memset(sz, 0, sizeof sz);
  memset(mark, 0, sizeof mark);
  return;
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, k, mx_idx, ans = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    cin >> a;
    nx[i] = a;
    if(i != a)  in[a].push_back(i);
  }
  for(int i = 1; i <= n; ++i) id[i] = i, intrsz[i] = 1;

  for(int i = 1; i <= n; ++i){
    memset(mark, 0, sizeof mark);
    if(nx[i] != i && has_cycle(i, i)){
      memset(mark, 0, sizeof mark);
      dfs(i);
      intrsz[i] = sz[i];
      paint(i, i);
    }
  }
  for(int i = 0; i < k; ++i){
    initialize(n);
    for(int j = 1; j <= n; ++j){
      if(era[j] != 1 && sz[j] == 0 && id[j] == j){
        dfs(j);
      }
    }
    mx_idx = 0;
    for(int j = 1; j <= n; ++j)
      if(id[j] == j && era[j] == 0 && sz[j] > sz[mx_idx])  mx_idx = j;
    if(mx_idx == 0){
      for(int i = 1; i <= n && resp.size() < k; ++i)
        resp.insert(i);
      break;
    }
    ans += sz[mx_idx];
    memset(mark, 0, sizeof mark);
    Erase(mx_idx);
    resp.insert(mx_idx);
  }
  cout << ans << "\n";

  for(set<int>::iterator it = resp.begin(); it != resp.end(); ++it)
    cout << (*it) << " ";
  cout << "\n";
  return 0;
}
