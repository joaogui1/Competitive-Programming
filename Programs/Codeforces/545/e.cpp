#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

int pai[300300];
vector<pll> adj[300300], edge;
ll dist[300300], in[300300];

void dijkstra(int u){
  int v, d;
  for(int i = 0; i < 300300; ++i) in[i] = dist[i] = (1LL << 50), pai[i] = i;
  dist[u] = in[u] = 0;
  priority_queue <pll, vector<pll>, greater<pll> > pq;
  pq.push(pll(0, u));

  while(pq.size()){
    while(pq.size()){
      u = pq.top().ss, d = pq.top().ff, pq.pop();
      if(dist[u] < d)  continue;
      break;
    }
    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].ss;
      if(dist[v] - dist[u] > adj[u][i].ff){
        pai[v] = u;
        in[v] = adj[u][i].ff;
        dist[v] = dist[u] + adj[u][i].ff;
        pq.push(pll(dist[v], v));
      }
      else if(dist[v] == dist[u] + adj[u][i].ff){
        if(in[v] > adj[u][i].ff){
          in[v] = adj[u][i].ff;
          pai[v] = u;
        }
      }
    }

  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pll ed;
  ll ans = 0;
  ll n, m, a, b, c;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    edge.push_back(pll(a, b));
    adj[a].push_back(pll(c, b));
    adj[b].push_back(pll(c, a));
  }
  cin >> a;
  dijkstra(a);
  for(int i = 1; i <= n; ++i) ans += in[i];
  cout << ans << "\n";
  for(int i = 0; i < m; ++i){
    ed = edge[i];
    if(pai[ed.ff] == ed.ss || pai[ed.ss] == ed.ff)  cout << i + 1 << " ";
  }
  cout << "\n";

  return 0;
}
