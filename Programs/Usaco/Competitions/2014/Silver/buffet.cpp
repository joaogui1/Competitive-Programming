#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

pll q[1024];
vector <int> adj[1024];
ll d[1024][1024], e, dp[1024];

ll f(int pos){
  if(dp[pos] != -1) return dp[pos];
  dp[pos] = q[pos].ff;
  for(int i = 1; i < pos; ++i){
    dp[pos] = max(dp[pos], q[pos].ff + f(i) - e*d[q[i].ss][q[pos].ss]);
  }
  return dp[pos];
}

void bfs(int x){
  int v, u;
  d[x][x] = 0LL;
  queue <int> q;
  q.push(x);
  while(q.size()){
    v = q.front();q.pop();
    for(int i = 0; i < adj[v].size(); ++i){
      u = adj[v][i];
      if(d[x][u] == 0 && u != x){
        d[x][u] = d[x][v] + 1;
        q.push(u);
      }
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("buffet.in");
  ofstream fout ("buffet.out");
  ll ans = -1;
  int n, dd, v;
  cin >> n >> e;
  for(int i = 1; i <= n; ++i){
    q[i].ss = i;
    cin >> q[i].ff >> dd;
    for(int j = 0; j < dd; ++j){
      cin >> v;
      adj[i].push_back(v);
    }
  }
  for(int i = 1; i <= n; ++i) bfs(i);
  sort(q + 1, q + n + 1);
  memset(dp, -1, sizeof dp);
  for(int i = 1; i <= n; ++i) ans = max(ans, f(i));
  cout << ans << "\n";

  return 0;
}
