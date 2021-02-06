#include <bits/stdc++.h>

using namespace std;

int dist[1 << 20];
vector <int> adj[1 << 20];

void bfs(int x){
  int u, v;
  dist[x] = 0;
  queue <int> q;
  q.push(x);
  while(q.size()){
    u = q.front();q.pop();
    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i];
      if(dist[v] == 0 && v != x){
        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
  return;
}

int main(){
  int n, x, y;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; ++i){
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  x = 1;
  bfs(1);
  for(int i = 1; i <= n; ++i)
    if(dist[i] > dist[x]) x = i;
  memset(dist, 0, sizeof dist);
  bfs(x);
  for(int i = 1; i <= n; ++i)
    if(dist[i] > dist[x]) x = i;
  printf("%d\n", dist[x]);
  return 0;
}
