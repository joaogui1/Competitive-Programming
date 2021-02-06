#include <bits/stdc++.h>

using namespace std;

int dist[10010], mark[10010];
queue <int> q;
vector <int> adj[10010];

int bfs(int n){
  int aux;
  dist[1] = 0;
  q.push(1);
  while(q.size()){
    aux = q.front();q.pop();
    for(int const & v: adj[aux])
      if(!mark[v]){
        dist[v] = dist[aux] + 1;
        mark[v] = 1;
        q.push(v);
      }
  }
  return dist[n];
}

void initialize(){
  memset(dist, 0, sizeof dist);
  memset(mark, 0, sizeof mark);
  for(int i = 0; i < 10010; ++i)  adj[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, a, b;
  cin >> t;

  while (t--){
    cin >> n >> m;
    initialize();

    for(int i = 0; i < m; ++i){
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    cout << bfs(n) << "\n";
  }

  return 0;
}
