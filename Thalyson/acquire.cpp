#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;

ll dp[2 << 16];
vector <pll> land, finland, hull;

bool comp(pll a, pll b, pll c){
  return (c.ss - a.ss)*(a.ff - b.ff) < (b.ss - a.ss)*(a.ff - c.ff);
}

ll f(int n){
  int l = 0, sz = 0;
  dp[0] = 0;
  hull.push_back(pll(finland[1].ss, 0));
  for(int i = 1; i <= n; ++i){
    sz = hull.size();
    if(sz <= l) l = sz - 1;
    dp[i] = (1LL << 50);
    while(l < sz - 1 && hull[l].ss + hull[l].ff*finland[i].ff > hull[l + 1].ss + hull[l + 1].ff*finland[i].ff) ++l;
    dp[i] = hull[l].ss + hull[l].ff*finland[i].ff;
    while(sz > 1 && comp(hull[sz - 2], hull[sz - 1], pll(finland[i + 1].ss, dp[i])))
      hull.pop_back(), --sz;
    hull.push_back(pll(finland[i + 1].ss, dp[i]));
  }
  return dp[n];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  ll x, y;
  cin >> n;
  land.assign(n, pll(0, 0));
  for(int i = 0; i < n; ++i)  cin >> land[i].ff >> land[i].ss;
  sort(land.begin(), land.end());

  finland.push_back(pll(0, (1LL << 50)));
  for(int i = 0; i < n; ++i){
    while(finland.size() && finland[finland.size() - 1].ss <= land[i].ss) finland.pop_back();
    finland.push_back(land[i]);
  }
  //for(int i = 0; i < finland.size(); ++i) cout << finland[i].ff << " " << finland[i].ss << "\n";

  cout << f(finland.size() - 1) << "\n";

  return 0;
}
