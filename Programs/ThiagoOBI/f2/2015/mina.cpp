#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1 << 28)

using namespace std;
typedef pair<int, int> pii;

int dist[100100];
vector <pii> adj[100100];

void dijkstra(int n){
  int u, v, d;
  dist[0] = 0;
  for(int i = 1; i < n*n; ++i)  dist[i] = INF;
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(0, 0));
  while(pq.size()){
    while(pq.size()){
      u = pq.top().ss, d = pq.top().ff, pq.pop();
      if(d != dist[u])  continue;
      break;
    }
    if(d != dist[u])  break;

    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].ss;
      if(dist[v] > dist[u] + adj[u][i].ff){
        dist[v] = dist[u] + adj[u][i].ff;
        pq.push(pii(dist[v], v));
      }
    }
  }
}

int main(){
  int n, aux;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      scanf("%d", &aux);
      if(j > 0) adj[i*n + j - 1].push_back(pii(aux, i*n + j));
      if(j + 1 < n)adj[i*n + j + 1].push_back(pii(aux, i*n + j));
      if(i > 0) adj[(i - 1)*n + j].push_back(pii(aux, i*n + j));
      if(i + 1 < n) adj[(i + 1)*n + j].push_back(pii(aux, i*n + j));
    }
  dijkstra(n);
  printf("%d\n", dist[n*n - 1]);
  return 0;
}
