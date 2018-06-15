#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int curnum, num_comp;
stack<int> st;
ll cost[100100];
int mark[100100];
vector<bool> incomp(100100, false);
vector<int> adj[100100], low(100100), num(100100, -1), comp[100100];

void scc(int u){
  st.push(u);
  incomp[u] = 1;

  low[u] = num[u] = curnum++;
  for(int i = 0; i < adj[u].size(); ++i){
    int v = adj[u][i];
    if(num[v] == -1){
      scc(v);
      low[u] = min(low[u], low[v]);
    }
    else if(incomp[v])  low[u] = min(low[u], num[v]);
  }

  if(num[u] == low[u]){
    int aux;
    while(1){
      aux = st.top(), st.pop();
      mark[aux] = 1;
      incomp[aux] = 0;
      comp[num_comp].push_back(aux);

      if(aux == u)  break;
    }
    ++num_comp;
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b;
  ll ans = 0, mi, cont = 1, aux_cont;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> cost[i];
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i = 1; i <= n; ++i)
    if(!mark[i])
      scc(i);
  for(int i = 0; i < num_comp; ++i){
    mi = 2000000000LL, aux_cont = 1;
    for(int j = 0; j < comp[i].size(); ++j){
      if(mi == cost[comp[i][j]])  ++aux_cont;
      else if(mi > cost[comp[i][j]]){
        aux_cont = 1;
        mi = cost[comp[i][j]];
      }
    }
    ans += mi, cont *= aux_cont;
    cont %= MOD;
  }

  cout << ans << " " << cont  << "\n";


  return 0;
}
