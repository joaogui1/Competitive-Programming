#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <int> adj[1024];
int dist[1024][1024], g[1024][1024];

int dfs(int s, int u){
  int v;
  for(int j = 0; j < adj[u].size(); ++j){
    v = adj[u][j];
    if(g[u][v] == 0)  continue;
    if(dist[s][v] == 0 && v != s){
      dist[s][v] = dist[s][u] + 1;
      dfs(s, v);
    }
  }
}

pii max_dist(int n, int s){
  int a, b;
  for(int i = 1; i <= n; ++i) dist[s][i] = 0;
  dfs(s, s);
  a = s;
  for(int i = 1; i <= n; ++i)
    if(dist[s][i] > dist[s][a]) a = i;
  for(int i = 1; i <= n; ++i) dist[a][i] = 0;
  dfs(a, a);
  b = a;
  for(int i = 1; i <= n; ++i)
    if(dist[a][i] > dist[a][b]) b = i;
  return pii(dist[a][b], a);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii aux1, aux2;
  int cen1, cen2;
  int n, a, b, mn = 10000, mx = -1, x11, x12, y11, y12, x21, x22, y21, y22, test, best;
  cin >> n;
  for(int i = 0; i < n - 1; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    g[a][b] = g[b][a] = 1;
  }

  mn = mx = max_dist(n, 1).ff;
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < adj[i].size(); ++j){
      best = 10000000;
      g[i][adj[i][j]] = g[adj[i][j]][i] = 0; //mata a aresta
      memset(dist, 0, sizeof dist);
      for(int k = 1; k <= n; ++k)
        dfs(k, k);
      for(int k = 1; k <= n; ++k){
        test = 0;
        if(dist[k][i] == 0 && i != k) continue;
        for(int l = 1; l <= n; ++l)
          test = max(test, dist[k][l]);
        if(test < best) best = test, cen1 = k;
      }
      best = 10000000;
      for(int k = 1; k <= n; ++k){
        test = 0;
        if(dist[k][i] != 0 || i == k) continue;
        for(int l = 1; l <= n; ++l)
          test = max(test, dist[k][l]);
        if(test < best) best = test, cen2 = k;
      }
      aux1 = max_dist(n, cen1), aux2 = max_dist(n, cen2);
      if(mx < aux1.ff + aux2.ff + 1){
        mx = aux1.ff + aux2.ff + 1;
        x21 = i;
        y21 = adj[i][j];
        x22 = aux1.ss;
        y22 = aux2.ss;
      }
      adj[cen1].push_back(cen2);
      adj[cen2].push_back(cen1);
      g[cen1][cen2] = g[cen2][cen1] = 1;
      aux1 = max_dist(n, 1);
      if(aux1.ff < mn){
        mn = aux1.ff;
        x11 = i;
        y11 = adj[i][j];
        x12 = cen1;
        y12 = cen2;
      }
      adj[cen1].pop_back();
      adj[cen2].pop_back();
      g[cen1][cen2] = g[cen2][cen1] = 0;
      g[i][adj[i][j]] = g[adj[i][j]][i] = 1; //ajeita a aresta
    }
  }

  cout << mn << " " << x11 << " " << y11 << " " << x12 << " " << y12 << "\n";
  cout << mx << " " << x21 << " " << y21 << " " << x22 << " " << y22 << "\n";
  return 0;
}
