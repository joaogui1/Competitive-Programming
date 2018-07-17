#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

vector <pii> adj[100100];
ll num[100100], sz[100100], cut[100100];

int cont(int u){
  int v;
  sz[u] = 1;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i].ff;
    if(sz[v] != -1) continue;
    sz[u] += cont(v);
  }
  return sz[u];
}

int dfs(int u, ll val){
  int v;
  cut[u] = 0;
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i].ff;
    if(cut[v] != -1)  continue;
    if(num[v] < val + adj[u][i].ss) cut[v] = sz[v];
    else  cut[v] = dfs(v, max(0LL, val + adj[u][i].ss));
    cut[u] += cut[v];
  }
  return cut[u];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b;
  cin >> n;
  memset(sz, -1, sizeof sz);
  memset(cut, -1, sizeof cut);
  for(int i = 1; i <= n; ++i)  cin >> num[i];
  for(int i = 2; i <= n; ++i){
    cin >> a >> b;
    adj[i].push_back(pii(a, b));
    adj[a].push_back(pii(i, b));
  }
  cont(1);
  cout << dfs(1, 0) << "\n";
  return 0;
}
