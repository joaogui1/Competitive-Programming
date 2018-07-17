#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, int> pii;

int n;
vector <pii> adj[200200];
ll dist[8][200200], dist_p[8][8][200020], imp[8];

void dijkstra(int x, int idx){
  for(int i = 0; i <= n; ++i) dist[idx][i] = (1LL << 49);
  pii u;
  dist[idx][x] = 0;
  priority_queue<pii, vector<pii>, greater <pii> > pq;
  pq.push(pii(0, x));
  while(pq.size()){
    u = pq.top(), pq.pop();
    if(dist[idx][u.ss] != u.ff) continue;
    for(pii &v: adj[u.ss])
      if(dist[idx][v.ss] > u.ff + v.ff){
        dist[idx][v.ss] = u.ff + v.ff;
        pq.push(pii(dist[idx][v.ss], v.ss));
      }
  }
}

void dijkstra2(int x, int y){
  priority_queue<pii, vector<pii>, greater <pii> > pq;
  for(int i = 0; i <= n; ++i){
    dist_p[x][y][i] = dist[x][i] + dist[y][i];
    pq.push(pii(dist_p[x][y][i], i));
  }
  pii u;
  while(pq.size()){
    u = pq.top(), pq.pop();
    if(dist_p[x][y][u.ss] != u.ff) continue;
    for(pii &v: adj[u.ss])
      if(dist_p[x][y][v.ss] > u.ff + v.ff){
        dist_p[x][y][v.ss] = u.ff + v.ff;
        pq.push(pii(dist_p[x][y][v.ss], v.ss));
      }
  }
}

ll sum1(vector <int> &v){
  ll ans = dist_p[0][v[0]][1] + dist_p[v[1]][v[2]][1];
  for(int i = 2; i <= n; ++i)
     ans = min(ans, dist_p[0][v[0]][i] + dist_p[v[1]][v[2]][i]);
  return ans;
}

ll sum2(vector <int> &v){
  ll ans = dist_p[0][v[0]][1] + dist_p[v[1]][v[2]][1] + dist[v[3]][1];
  for(int i = 2; i <= n; ++i) ans = min(ans, dist_p[0][v[0]][i] + dist_p[v[1]][v[2]][i] + dist[v[3]][i]);
  return ans;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll c, ans = (1LL << 49);
  int k, m, a, b;
  vector <int> v;
  cin >> n >> k >> m;
  for(int i = 0; i < k; ++i)  cin >> imp[i];
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    adj[a].push_back(pii(c, b));
    adj[b].push_back(pii(c, a));
  }
  for(int i = 0; i < k; ++i)  dijkstra(imp[i], i);
  if(k == 2){
    ans = dist[0][imp[1]];
  }
  else if(k == 3){
    ans = dist[0][1] + dist[1][1] + dist[2][1];
    for(int i = 2; i <= n; ++i) ans = min(ans, dist[0][i] + dist[1][i] + dist[2][i]);
  }

  else if(k == 4){
    for(int i = 0; i < k; ++i)
      for(int j = i + 1; j < k; ++j)
        dijkstra2(i, j);
    for(int i = 1; i < k; ++i) v.push_back(i);
    ans = sum1(v);
    while(next_permutation(v.begin(), v.end()))
      if(v[1] < v[2])  ans = min(ans, sum1(v));
  }

  else if(k == 5){
    for(int i = 0; i < k; ++i)
      for(int j = i + 1; j < k; ++j)
        dijkstra2(i, j);
    for(int i = 1; i < k; ++i) v.push_back(i);
    ans = ans, sum2(v);
    while(next_permutation(v.begin(), v.end()))
      if(v[1] < v[2]) ans = min(ans, sum2(v));
  }
  cout << ans << "\n";
  return 0;
}
