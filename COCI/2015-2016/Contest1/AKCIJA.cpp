#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> v;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  ll ans = 0;
  cin >> n;
  v.assign(n, 0);
  for(int i = 0; i < n; ++i)  cin >> v[i];
  for(int i = 0; i < n; ++i)  ans += v[i];
  sort(v.rbegin(), v.rend());
  for(int i = 2; i < n; i += 3) ans -= v[i];
  cout << ans << "\n";

  return 0;
}
