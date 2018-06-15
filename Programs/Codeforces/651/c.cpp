#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

map <ll, ll> mx;
map <ll, ll> my;
vector <pii> mp;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll ans = 0, beg;
  pii aup;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aup.ff >> aup.ss;
    mp.push_back(aup);
    if(mx.count(aup.ff) == 0) mx[aup.ff] = 1;
    else  ++mx[aup.ff];
    if(my.count(aup.ss) == 0) my[aup.ss] = 1;
    else  ++my[aup.ss];
  }
  sort(mp.begin(), mp.end());
  for(ll i = 0; i < n; ++i){
    beg = i;
    for(; mp[i] == mp[i + 1] && i + 1 < n; ++i);
    ans -= ((i - beg)*(i - beg + 1)/2);
  }
  for(auto v: mx)
    ans += (v.ss)*(v.ss - 1)/2;
  for(auto v: my)
    ans += (v.ss)*(v.ss - 1)/2;
  cout << ans << "\n";
  return 0;
}
