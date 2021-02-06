#include <bits/stdc++.h>
#define INF (1LL << 50)

using namespace std;
typedef long long int ll;

ll dist[4][40010], n, m;
vector <ll> adj[40010];

void bfs(int x, int idx){
  int u;
  queue <int> q;
  for(int i = 0; i <= n; ++i) dist[idx][i] = INF;
  dist[idx][x] = 0;
  q.push(x);
  while(q.size()){
    u = q.front();
    q.pop();
    for(int i = 0; i < adj[u].size(); ++i)
      if(dist[idx][adj[u][i]] == INF){
        dist[idx][adj[u][i]] = 1 + dist[idx][u];
        q.push(adj[u][i]);
      }
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("piggyback.in");
  ofstream fout ("piggyback.out");
  ll b, e, p, x, y;
  ll ans = INF;
  fin >> b >> e >> p >> n >> m;
  for(int i = 0; i < m; ++i){
    fin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bfs(1, 1);
  bfs(2, 2);
  bfs(n, 0);
  for(int i = 1; i <= n; ++i) ans = min(ans, dist[1][i]*b + dist[2][i]*e + dist[0][i]*p);
  fout << ans << "\n";
}
