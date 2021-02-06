#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1 << 20)

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<pii, pii> ppp;

int dist[3010][3010];
vector <int> adj[3010];
vector<pii> mdist[3010];
vector<ppi> vec[3010];

void bfs(int u){
  int v;
  queue<int> q;
  q.push(u);
  dist[u][u] = 0;
  while(q.size()){
    v = q.front();q.pop();
    for(int i = 0; i < adj[v].size(); ++i){
      if(dist[u][adj[v][i]] == INF){
        dist[u][adj[v][i]] = 1 + dist[u][v];
        q.push(adj[v][i]);
      }
    }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  pii aup;
  ppp ans;
  int n, m, a, b, best, test;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      dist[i][j] = (1 << 20);

  for(int i = 1; i <= n; ++i){
    bfs(i);
    for(int j = 1; j <= n; ++j) if(dist[i][j] != INF && i != j) mdist[i].push_back(pii(dist[i][j], j));
    sort(mdist[i].rbegin(), mdist[i].rend());
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < mdist[i].size(); ++j){
      aup = mdist[i][j];
      b = 0;
      if(mdist[aup.ss][0].ss != i)
        vec[i].push_back(ppi(aup.ff + mdist[aup.ss][0].ff, pii(aup.ss, mdist[aup.ss][0].ss)));
      else
        vec[i].push_back(ppi(aup.ff + mdist[aup.ss][1].ff, pii(aup.ss, mdist[aup.ss][1].ss)));
    }
    sort(vec[i].rbegin(), vec[i].rend());
  }

  best = -1;
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < mdist[i].size(); ++j){
      a = mdist[i][j].ss;
      b = 0;
      while(b < vec[a].size() && (vec[a][b].ss.ff == i || vec[a][b].ss.ss == i)) ++b;
      if(b >= vec[a].size())  continue;
      if(mdist[i][j].ff + vec[a][b].ff > best){
        best = mdist[i][j].ff + vec[a][b].ff;
        ans = ppp(pii(i, a), pii(vec[a][b].ss.ff, vec[a][b].ss.ss));
      }
    }
  }
  cout << ans.ff.ff << " " << ans.ff.ss << " " << ans.ss.ff << " " << ans.ss.ss << "\n";

  return 0;
}
