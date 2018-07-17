#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> v[4];

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  ll n, aux, ans;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    ans = 0;
    cin >> n;
    v[0].clear();v[1].clear();
    for(int j = 0; j < 2; ++j)
      for(int k = 0; k < n; ++k){
        cin >> aux;
        v[j].push_back(aux);
      }
    sort(v[0].begin(), v[0].end());
    sort(v[1].rbegin(), v[1].rend());
    for(int j = 0; j < n; ++j)
      ans += v[0][j]*v[1][j];
    cout << "Case #" << i << ": " << ans << "\n";
  }


  return 0;
}
