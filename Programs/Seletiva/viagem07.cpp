#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1 << 29)

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> pii;
typedef pair <pii, ll> ppi;
typedef pair <ll, pii> pip;
typedef pair <ppi, ll> ppp;

ppi dist[1024];
vector <pip> adj[1024];

void dijkstra(int x){
  ppi d;
  int u, v;
  dist[x] = ppi(pii(0, 0), -1);
  priority_queue <ppp, vector<ppp>, greater<ppp> > pq;
  pq.push(ppp(dist[x], x));
  while(pq.size()){
    while(pq.size()){
      u = pq.top().ss, d = pq.top().ff;pq.pop();
      if(dist[u] != d)  continue;
      break;
    }
    if(dist[u] != d)  break;
    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].ff;
      if(dist[v] > ppi(pii(dist[u].ff.ff + adj[u][i].ss.ff, dist[u].ff.ss + adj[u][i].ss.ss), dist[u].ss + 1)){
        dist[v] = dist[u];
        dist[v].ss += 1;
        dist[v].ff.ff += adj[u][i].ss.ff;
        dist[v].ff.ss += adj[u][i].ss.ss;
        pq.push(ppp(dist[v], v));
      }
    }
  }
  return;
}

int main(){
  char op;
  int n, f, u, v, x, y, d, t;
  scanf("%d %d %c %d %d", &n, &f, &op, &u, &v);
  for(int i = 0; i <= n; ++i)
    dist[i] = ppi(pii(INF, INF), INF);
  for(int i = 0; i < f; ++i){
    scanf("%d %d %d %d", &x, &y, &d, &t);
    if(op == 'P')
      adj[x].push_back(pip(y, pii(d, t)));
    else
      adj[x].push_back(pip(y, pii(t, d)));
  }
  dijkstra(u);
  if(u == v)  dist[v].ss = 0;
  if(dist[v].ss == INF) cout << "-1\n";
  else if(op == 'P')
    cout << dist[v].ff.ff << " " << dist[v].ff.ss << " " << dist[v].ss << "\n";
  else
    cout << dist[v].ff.ss << " " << dist[v].ff.ff << " " << dist[v].ss << "\n";

  return 0;
}
