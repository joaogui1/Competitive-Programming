#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppl;

pii v[1024];
set <pii> s;
ppl proc[1024];
vector <int> adj[1024];
int ans[1024], light[1024];

void dfs(int u, int t){
  ans[u] = t;
  for(int &v: adj[u]){
    if(light[v] > 0){
      --light[v];
      if(light[v] == 0) dfs(v, t);
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii aux;
  int n;
  cin >> n;
  auto it = s.begin();
  cin >> aux.ff >> aux.ff >> aux.ss >> aux.ss;
  for(int i = 1; i <= n; ++i)  cin >> v[i].ff >> v[i].ss, proc[i].ff = v[i], proc[i].ss = i;
  for(int i = 1; i <= n; ++i) cin >> light[i];

  sort(proc + 1, proc + n + 1);
  for(int i = n; i > 0; --i){
    if(s.size() == 0){
      s.insert(pii(proc[i].ff.ss, proc[i].ss));
      continue;
    }
    it = s.lower_bound(pii(proc[i].ff.ss, proc[i].ss));
    cout << ((s.begin()) -> ff) << " " << ((s.begin()) -> ss) << " " << proc[i].ff.ss << " " << proc[i].ss << "\n";
    if(it == s.end()) continue;
    if(v[it -> ss].ss < proc[i].ff.ss || v[it -> ss].ff < proc[i].ff.ff)  ++it;
    for(; it != s.end(); ++it)  adj[proc[i].ss].push_back(it -> ss);

  }
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j < adj[i].size(); ++j)
      cout << adj[i][j] << " \n"[j + 1 == adj[i].size()];
  // for(int i = 1; i <= n; ++i)
  //   for(int j = 1; j <= n; ++j)
  //     if(v[i].ff <= v[j].ff && v[i].ss <= v[j].ss)  adj[i].push_back(j);
  for(int i = 1; i <= n; ++i)
    if(light[i] != 0){
      light[i] = 0;
      dfs(i, i);
    }

  for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
  return 0;
}
