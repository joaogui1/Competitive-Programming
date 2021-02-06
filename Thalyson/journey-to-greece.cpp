#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <int> sites;
vector <pii> adj[20010];
int dist[32][20010], dp[2][20][1 << 20], n, p, t;

void dijkstra(int s){
  int u, v, d;
  priority_queue <pii, vector<pii>, greater <pii> > pq;
  dist[s][sites[s]] = 0;
  pq.push(pii(dist[s][sites[s]], sites[s]));
  while(pq.size()){
    while(pq.size()){
      u = pq.top().ss;
      d = pq.top().ff;  pq.pop();
      if(d != dist[s][u]) continue;
      break;
    }
    if(d != dist[s][u]) break;
    for(int i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].ss;
      if(dist[s][v] > adj[u][i].ff + d){
        dist[s][v] = d + adj[u][i].ff;
        pq.push(pii(dist[s][v], v));
      }
    }
  }
}

int tsp(int hast, int u, int mask){
  int shadow;
  if(dp[hast][u][mask] != -1) return dp[hast][u][mask];
  if(!hast && mask == (1 << p + 1) - 1) return dp[hast][u][mask] = dist[u][0];
  if(hast && mask == (1 << p + 1) - 1) return dp[hast][u][mask] = min(dist[u][0], t);
  dp[hast][u][mask] = (1 << 28);
  for(int i = 1; i <= p; ++i){
    if((1 << i)&mask) continue;
    shadow = mask|(1 << i);
    dp[hast][u][mask] = min(dp[hast][u][mask], dist[u][sites[i]] + tsp(hast, i, shadow));
    if(hast)
      dp[hast][u][mask] = min(dp[hast][u][mask], t + tsp(0, i, shadow));
  }
  return dp[hast][u][mask];
}

void initialize(){
  for(int i = 0; i < 20; ++i)
    for(int j = 0; j < 20010; ++j)
      dist[i][j] = (1 << 28);
  memset(dp, -1, sizeof dp);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  initialize();
  int m, g, a, b, w;
  cin >> n >> p >> m >> g >> t;
  sites.assign(p + 1, 0);
  for(int i = 1; i <= p; ++i){
    cin >> sites[i] >> w;
    if(sites[i] == 0) --i, --p;
    g -= w;
  }
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> w;
    adj[a].push_back(pii(w, b));
    adj[b].push_back(pii(w, a));
  }
  for(int i = 0; i <= p; ++i)
    dijkstra(i);

  if(tsp(0, 0, 1) <= g)
    cout << "possible without taxi\n";
  else if(tsp(1, 0, 1) <= g)
    cout << "possible with taxi\n";
  else
    cout << "impossible\n";
  return 0;
}
