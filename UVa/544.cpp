#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> adj[256];
map <string, int> mapa;
int G[256][256], cont, dist[256];

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] = max(G[i][j], min(G[i][k], G[k][j]));
  return;
}

void dijkstra(int n, int k){
  int idx, v, d;
  dist[k] = (1 << 29);
  priority_queue < pii > pq;
  pq.push(pii((1 << 29), k));
  while(pq.size()){
    idx = -1;
    while(pq.size()){
      v = pq.top().ss;
      d = pq.top().ff;
      pq.pop();
      if(dist[v] != d)  continue;
      idx = v;
      break;
    }
    if(idx == -1) break;

    for(pii const & e : adj[idx])
      if(dist[e.second] < min(dist[idx], e.first)){
        dist[e.second] = min(dist[idx], e.first);
        pq.push(pii(dist[e.second], e.second));
      }

  }
  return;
}

void initialize(int n){
  cont = 0;
  mapa.clear();
  memset(G, 0, sizeof G);
  for(int i = 1; i <= 255; ++i) adj[i].clear();
  for(int i = 1; i <= 255; ++i) dist[i] = 0;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, r, aux;
  string aus, aur;
  cin >> n >> r;
  for(int t = 1; (n || r); ++t){
    initialize(n);
    for(int i = 0; i < r; ++i){
      cin >> aus >> aur >> aux;
      if(!mapa.count(aus))
        mapa[aus] = ++cont;

      if(!mapa.count(aur))
        mapa[aur] = ++cont;

      //G[mapa[aus]][mapa[aur]] = G[mapa[aur]][mapa[aus]] = aux;
      adj[mapa[aus]].push_back(pii(aux, mapa[aur]));
      adj[mapa[aur]].push_back(pii(aux, mapa[aus]));
    }

    //fw(n);
    cin >> aus >> aur;
    dijkstra(n, mapa[aus]);
    cout << "Scenario #" << t << "\n" << dist[mapa[aur]] << " tons\n\n";
    cin >> n >> r;
  }




  return 0;
}
