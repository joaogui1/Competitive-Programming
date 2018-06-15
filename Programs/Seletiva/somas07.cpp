#include <bits/stdc++.h>

using namespace std;

int id[100100];
unordered_map <int, int> s;
vector <int> p, adj[100100], ans[4], vec;

bool dfs(int u, int ego){
  int v;
  bool ret = 1;
  id[u] = ego;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(id[v] == id[u] && v != u)  return 0;
    if(id[v] == 0)
      ret &= dfs(v, (ego&1) + 1);
  }
  return ret;
}

int main(){
  int n, m, a;
  bool vdc = 1;

  scanf("%d %d", &n, &m);
  p.assign(m, 0);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a);
    s[a] = i;
    vec.push_back(a);
  }
  for(int i = 0; i < m; ++i)  scanf("%d", &p[i]);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(s.count(p[j] - vec[i]))
        adj[i].push_back(s[p[j] - vec[i]]);
    }
  }

  for(int i = 0; i < n; ++i)
    if(id[i] == 0)
      vdc &= dfs(i, 1);

  if(vdc){
    for(int i = 1; i < 3; ++i){
      for(int j = 0; j < n; ++j)
        if(id[j] == i)  ans[i].push_back(vec[j]);
      sort(ans[i].begin(), ans[i].end());
      printf("%d", (int)ans[i].size());
      for(int j = 0; j < ans[i].size(); ++j)
        printf(" %d", ans[i][j]);
      printf("\n");
    }
    return 0;
  }
  printf("-1\n-1\n");
  return 0;
}
