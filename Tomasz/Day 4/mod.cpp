#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> edges;
vector <int> adj[1024];
int dist[1024][1024], p[1024], g[1024][1024];

void dfs(int s, int u){
  int v;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(g[u][v] == 0)  continue;
    if(dist[s][v] == 0 && v != s){
      p[v] = u;
      dist[s][v] = dist[s][u] + 1;
      dfs(s, v);
    }
  }
}

pii calc_max(int s){
  int a = s, b;
  memset(dist[s], 0, sizeof dist[s]);
  dfs(s, s);
  for(int i = 1; i <= n; ++i)
    if(dist[s][i] < dist[s][a]) a = i;
  b = a;
  memset(dist[a], 0, sizeof dist[a]);
  dfs(a, a);
  for(int i = 1; i <= n; ++i)
    if(dist[a][i] > dist[a][b]) b = i;
  return pii(b, dist[a][b]);
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  pii e, aux1, aux2;
  int n, a, b, mn, mx, cen = 1, best = 1000000, aux, x1, y1, x2, y2, k = 0;
  cin >> n;
  for(int i = 0; i < n - 1; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges.push_back(pii(a, b));
    g[a][b] = g[b][a] = 1;

  }
  mn = mx = calc_max(1).ss;
  for(int i = 0; i < edges.size(); ++i){
    e = edges[i];
    g[e.ff][e.ss] = g[e.ss][e.ff] = 0;
    aux1 = 
  }


  return 0;
}
