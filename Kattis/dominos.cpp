#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100100];
int mark[100100], finish[100100], pos[100100], fin_cont;

void dfs(int x){
  mark[x] = 1;
  for(int const v: adj[x])
    if(!mark[v])
      dfs(v);
  finish[x] = ++fin_cont;
  return;
}

bool comp(int a, int b){
  return finish[a] > finish[b];
}

void initialize(int n){
  memset(pos, 0, sizeof pos);
  memset(mark, 0, sizeof mark);
  memset(finish, 0, sizeof finish);
  for(int i = 0; i <= n; ++i) adj[i].clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, ans, x, y;
  cin >> t;
  while(t--){
    cin >> n >> m;
    ans = 0;
    initialize(n);
    for(int i = 0; i < m; ++i){
      cin >> x >> y;
      adj[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i)
      if(!mark[i])  dfs(i);
    for(int i = 1; i <= n; ++i) pos[i] = i;
    sort(pos + 1, pos + n + 1, comp);
    memset(mark, 0, sizeof mark);
    for(int i = 1; i <= n; ++i)
      if(!mark[pos[i]]){
        ++ans;
        dfs(pos[i]);
      }

    cout << ans << "\n";
  }



return 0;
}
