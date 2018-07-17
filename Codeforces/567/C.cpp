#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> v;
map <ll, ll> l, r;

int main(){
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  v.assign(n, 0);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    if(r.count(v[i])) ++r[v[i]];
    else  r[v[i]] = 1;
    l[v[i]] = 0;
  }
  for(int i = 0; i < n; ++i){
    --r[v[i]];
    if(v[i] % k == 0) ans += l[v[i]/k]*r[v[i]*k];
    ++l[v[i]];
    //cout << ans << endl;
  }
  cout << ans << "\n";
  return 0;

}
