#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int dist[1024];
vector <pii> adj[1024];

void dijkstra(int n){
  pii aux;
  int u = -1, v, w;
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(0, 0));
  while(pq.size()){
    u = -1;
    while(pq.size()){
      aux = pq.top(); pq.pop();
      if(dist[aux.ss] != aux.ff)  continue;
      u = aux.ss;
      break;
    }
    if(u == -1) break;

    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].ff, w = adj[u][i].ss;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push(pii(dist[v], v));
      }
    }
  }
  printf("%d\n", dist[n]);
  return;
}

int main(){
  int n, m, b, u, v;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d %d", &u, &v, &b);
    adj[u].push_back(pii(v, b));
    adj[v].push_back(pii(u, b));
  }
  for(int i = 1; i < n + 2; ++i)  dist[i] = (1 << 28);

  dijkstra(n + 1);
  return 0;
}
