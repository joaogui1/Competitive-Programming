#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1 << 30)

using namespace std;
typedef pair<int, int> pii;

pii coins[1024];
int cost[1024], G[1024][1024], dist[1024];

void calc(int m){
  cost[0] = 0;
  for(int i = 1; i < 1024; ++i)
    for(int j = 0; j < m; ++j){
      if(i > coins[j].ss)
        cost[i] = min(cost[i], cost[i - coins[j].ss] + coins[j].ff);
      else
        cost[i] = min(cost[i], coins[j].ff);
    }
}

void dijkstra(int n){
  int u, d;
  dist[0] = 0;
  for(int i = 1; i < 1024; ++i) dist[i] = INF;

  priority_queue<pii, vector<pii>, greater <pii> > pq;
  pq.push(pii(0, 0));
  while(pq.size()){
    while(pq.size()){
      u = pq.top().ss;
      d = pq.top().ff;
      pq.pop();
      if(dist[u] != d)  continue;
      break;
    }
    if(dist[u] != d)  continue;

    for(int i = 1; i <= n; ++i)
      if(G[u][i] >= 0)
        if(G[u][i] > -1 && dist[i] > d + G[u][i]){
          dist[i] = d + G[u][i];
          pq.push(pii(dist[i], i));
        }
  }
}

void initialize(){
  memset(G, -1, sizeof G);
  for(int i = 0; i < 1024; ++i)
    coins[i].ff = coins[i].ss = INF;
  for(int i = 0; i < 1024; ++i) cost[i] = dist[i] = INF;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int m, n, g, k, a, b, v;
  while(1){
    initialize();
    cin >> m >> n >> g >> k;
    if(m == 0 && n == 0 && g == 0 && k == 0)  break;
    for(int i = 0; i < m; ++i)  cin >> coins[i].ff >> coins[i].ss;
    for(int i = 0; i < g; ++i){
      cin >> a >> b;
      G[a][b] = G[b][a] = 0;
    }

    calc(m);
    G[0][1] = 0;

    for(int i = 0; i < k; ++i){
      cin >> a >> b;
      for(int j = 0; j <= n; ++j)
        if(G[j][a] > -1)  G[j][a] += cost[b];
    }
    dijkstra(n);
    cout << ((dist[n] >= INF)?-1:(dist[n])) << "\n";
  }
  return 0;
}
