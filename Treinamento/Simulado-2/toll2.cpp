#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, int> pii;

map<int, int> dict;
map<int, int> _dict;
ll dist[3001][50010];
vector <pii> adj[50010];

void dijkstra(int n, int x){
  pii u;
  for(int i = 0; i < n; ++i)  dist[x][i] = (1LL << 49);
  dist[x][_dict[x]] = 0;
  // cout << x << " " << _dict[x] << "\n";
  priority_queue<pii, vector<pii>, greater<pii> >pq;
  pq.push(pii(0, _dict[x]));
  while(pq.size()){
    while(pq.size() && pq.top().ff != dist[x][pq.top().ss])  pq.pop();
    if(!pq.size())  break;
    u = pq.top(), pq.pop();
    //cout << u.ff << " " << u.ss << "\n";
    for(pii &v: adj[u.ss])
      if(dist[x][v.ss] > u.ff + v.ff){
        dist[x][v.ss] = u.ff + v.ff;
        pq.push(pii(dist[x][v.ss], v.ss));
      }
  }
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, m, o, a, b, t, cnt = 0;
  cin >> k >> n >> m >> o;

  for(int i = 0; i < m; ++i){
    cin >> a >> b >> t;
    adj[a].push_back(pii(t, b));
    adj[b].push_back(pii(t, a));
  }

  for(int i = 0; i < o; ++i){
    cin >> a >> b;
    if(!dict.count(a)){
      dict[a] = cnt;
      _dict[cnt] = a;
      dijkstra(n, cnt);
      ++cnt;
    }
    a = dict[a];
    cout << ((dist[a][b] != (1LL << 49))?dist[a][b]:-1) << "\n";
  }



  return 0;
}
