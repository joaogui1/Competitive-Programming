#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;

int g[100100];
ll dist[100100];
vector<ppl> adj[100100];

void dijkstra(int n){
  pll u, v;
  for(int i = 2; i <= n; ++i) dist[i] = (1LL << 54);
  priority_queue<pll, vector<pll>, greater<pll> > pq;
  pq.push(pll(0, 1));
  while(pq.size()){
    while(pq.size()){
      u = pq.top(), pq.pop();
      if(dist[u.ss] != u.ff) continue;
      break;
    }
    for(int i = 0; i < adj[u.ss].size(); ++i){
      v = adj[u.ss][i].ff;
      if(dist[v.ss] > dist[u.ss] + v.ff){
        dist[v.ss] = dist[u.ss] + v.ff;
        pq.push(pll(dist[v.ss], v.ss));
      }
    }
  }
  return;
}

void build_graph(int n){
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j < adj[i].size(); ++j)
      if(dist[i] + adj[i][j].ff.ff == dist[adj[i][j].ff.ss])
        ++g[adj[i][j].ff.ss];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, m, k, a, b, c, ans = 0;
  cin >> n >> m >> k;
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    adj[a].push_back(ppl(pll(c, b), 0));
    adj[b].push_back(ppl(pll(c, a), 0));
  }
  for(int i = 0; i < k; ++i){
    cin >> a >> c;
    adj[1].push_back(ppl(pll(c, a), 1));
    adj[a].push_back(ppl(pll(c, 1), 1));
  }

  dijkstra(n);


  build_graph(n);


  for(int i = 0; i < adj[1].size(); ++i){
    if(adj[1][i].ss == 0) continue;
    if(adj[1][i].ff.ff != dist[adj[1][i].ff.ss])  ++ans;
    else  if(g[adj[1][i].ff.ss] > 1){
      ++ans;
      --g[adj[1][i].ff.ss];

    }
  }
  cout << ans << "\n";

  return 0;
}
