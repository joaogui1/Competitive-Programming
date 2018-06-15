#include <bits/stdc++.h>
#define MOD 1000000007
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

ll cost[100100];
int mark[100100];
pll dp[2][100100];
vector <pll> adj[100100];
vector <pll> child[100100];

pll f(int use, int idx){
  if(dp[use][idx].ff != 0) return dp[use][idx];
  if(child[idx].size() == 0 && use) return pll(cost[idx], 1);
  if(child[idx].size() == 0 && !use)  return pll(0, 1);
  pll aux, auy;
  dp[use][idx].ss = 1LL;

  for(pll const & e : child[idx]){
    aux = f(1, e.ff);
    dp[use][idx].ff += aux.ff;
    dp[use][idx].ss *= aux.ss;
    if(dp[use][idx].ss >= MOD)  dp[use][idx].ss %= MOD;
  }

  if(use){
    ll tot = dp[use][idx].ff;
    ll mult = dp[use][idx].ss;
    dp[use][idx].ff += cost[idx];

    for(pll const & e : child[idx]){
      aux = f(1, e.ff);
      auy = f(0, e.ff);

      if(dp[use][idx].ff > tot - aux.ff + e.ss + auy.ff){
        dp[use][idx].ff = tot - aux.ff + e.ss + auy.ff;
        dp[use][idx].ss = (mult*auy.ss)/(aux.ss);
        if(dp[use][idx].ss >= MOD)  dp[use][idx].ss %= MOD;
      }

      else if(dp[use][idx].ff == tot - aux.ff + e.ss + auy.ff){
        dp[use][idx].ss += (mult*auy.ss)/(aux.ss);
        if(dp[use][idx].ss >= MOD)  dp[use][idx].ss %= MOD;
      }
    }
  }

  return dp[use][idx];
}

void dfs(int x){
  mark[x] = 1;
  for(pll const & e: adj[x])
    if(!mark[e.ff]){
      child[x].push_back(pll(e.ff, e.ss));
      dfs(e.ff);
    }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll a, b, c;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> cost[i + 1];
  for(int i = 0; i < n - 1; ++i){
    cin >> a >> b >> c;
    adj[a].push_back(pll(b, c));
    adj[b].push_back(pll(a, c));
  }

  dfs(1);
  f(1, 1);

  cout << dp[1][1].ff << " " << dp[1][1].ss << "\n";
  return 0;
}
