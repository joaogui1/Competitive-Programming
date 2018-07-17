#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

bool g[16][16];
set <pii> ed;
vector <int> adj[50010];
int mark[50010], d[50010];
priority_queue <pii, vector<pii>, greater<pii> > pq;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, u, v, ans = 1, sz, test, vdc;

  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> d[i];
    pq.push(pii(d[i], i));
    for(int j = 0; j < d[i]; ++j){
      cin >> u;
      adj[i].push_back(u);
      ed.insert(pii(i, u));
    }
  }
  while(1){
    while(pq.size() && mark[pq.top().ss]) pq.pop();
    if(pq.size() == 0)  break;
    vector <int> aux;
    u = pq.top().ss, pq.pop();

    d[u] = 0;
    mark[u] = 1;
    aux.push_back(u);
    memset(g, 0, sizeof g);
    for(int &v : adj[u]){
      if(!mark[v]){
        --d[v];
        aux.push_back(v);
        pq.push(pii(d[v], v));
      }
    }
    sz = aux.size();
    // cout << u << ": ";
    // for(int i = 0; i < aux.size(); ++i) cout << aux[i] << " \n"[i + 1 == aux.size()];
    for(int i = 0; i < sz; ++i)
      for(int j = 0; j < sz; ++j){
        g[i][i] = 1;
        if(i != j && ed.count(pii(aux[i], aux[j]))) g[i][j] = 1;
      }

    for(int mask = 1; mask < (1 << sz); mask += 2){
      vdc = 1;
      test = 0;
      for(int j = 0; j < sz; ++j){
        if(!(mask & (1 << j)))  continue;
        ++test;
        for(int k = 0; k < sz; ++k)
          if((mask & (1 << k)) && !g[j][k]) vdc = 0;
      }
      if(vdc) ans = max(ans, test);
    }
  }

  cout << ans << '\n';

  return 0;
}
