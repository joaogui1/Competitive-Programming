#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1LL << 49)

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int n;
pii itens[128][1024];
ll dist[128], _dist[128];
vector<pii> adj[128], _adj[128];

void dijkstra(int x){
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for(int i = 0; i <= n; ++i) dist[i] = INF;
  pii u;
  dist[x] = 0;
  pq.push(pii(0, x));
  while(pq.size()){
    u = pq.top(), pq.pop();
    if(dist[u.ss] != u.ff)  continue;
    for(pii &v: adj[u.ss])
      if(dist[v.ss] > v.ff + u.ff){
        dist[v.ss] = v.ff + u.ff;
        pq.push(pii(dist[v.ss], v.ss));
      }
  }
}

void _dijkstra(int x){
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for(int i = 0; i <= n; ++i) _dist[i] = INF;
  pii u;
  _dist[x] = 0;
  pq.push(pii(0, x));
  while(pq.size()){
    u = pq.top(), pq.pop();
    if(_dist[u.ss] != u.ff)  continue;
    for(pii &v: _adj[u.ss])
      if(_dist[v.ss] > v.ff + u.ff){
        _dist[v.ss] = v.ff + u.ff;
        pq.push(pii(_dist[v.ss], v.ss));
      }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll ans = 0;
  int m, k, a, b, c;
  cin >> n >> m >> k;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      cin >> itens[i][j].ff >> itens[i][j].ss;
      if(itens[i][j].ff == -1)  itens[i][j].ff = INF;
      if(itens[i][j].ss == -1)  itens[i][j].ss = -INF;
    }
  }

  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    adj[a].push_back(pii(c, b));
    _adj[b].push_back(pii(c, a));
  }
  dijkstra(1), _dijkstra(1);
  for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= k; ++j){
      ans = max(ans, (itens[i][j].ss - itens[1][j].ff)/(dist[i] + _dist[i]));
      //cout << ans << " " << itens[i][j].ss - itens[1][j].ff << " " << dist[i] + _dist[i] << "\n";
    }
  cout << ans << "\n";

  return 0;
}
