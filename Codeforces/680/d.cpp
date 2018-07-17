#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

ll cube(ll x){
  return x*x*x;
}

ll cb_rt(ll x){
  ll ans = 0;
  for(ll pot = 20; pot > -1; --pot)
    if(cube(ans + (1LL << pot)) <= x) ans += (1LL << pot);
  return ans;
}

pll f(ll v){
  if(v < 8) return pll(v, v);
  ll l = cb_rt(v);
  pll id = f(v - cube(l));
  pll ego = f(cube(l) - cube(l - 1) - 1);
  if(id.ff >= ego.ff)
    return pll(id.ff + 1, id.ss + cube(l));
  else
    return pll(ego.ff + 1, ego.ss + cube(l - 1));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pll ans;
  ll m, cb_r = 1, hp;
  cin >> m;
  ans = f(m);
  cout << ans.ff << " " << ans.ss << "\n";
  return 0;
}
