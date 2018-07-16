#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF (1LL << 57)

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int n;
bool reach[128][128];
pii itens[128][1024];
ll g[128][128], dist[128][128], profit[128][128];

void fw(){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        reach[i][j] |= (reach[i][k] && reach[k][j]);
      }
}


bool fw(ll r){

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(reach[i][j])
        dist[i][j] = r*g[i][j] - profit[i][j];

  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j){
        if(!reach[i][k] || !reach[k][j])  continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }

  for(int i = 1; i <= n; ++i)
    if(dist[i][i] <= 0)  return 1;
  return 0;
}

void pre_calc(int k){
  for(int l = 1; l <= n; ++l)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= k; ++j)
        if((itens[i][j].ss != -1) && (itens[l][j].ff != -1))
          profit[l][i] = max(profit[l][i], itens[i][j].ss - itens[l][j].ff);
}

ll bin_search(ll ini, ll fim){
  ll m, ans = 0;
  while(fim - ini > 1){
    m = (fim + ini)/2;
    if(fw(m)){
      ans = m;
      ini = m;
    }
    else  fim = m;
  }
  return ans;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int m, k, a, b;
  ll ans = 0, test = 0, c;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      g[i][j] = INF, dist[i][j] = INF;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= k; ++j)
      cin >> itens[i][j].ff >> itens[i][j].ss;


  pre_calc(k);

  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    g[a][b] = c;
    reach[a][b] = 1;
  }
  fw();
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      test = max(test, profit[i][j]);
  //cout << test << "\n";
  ans = bin_search(0, test + 1);
  cout << ans << "\n";

  return 0;
}
