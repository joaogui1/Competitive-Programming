#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> v;

ll f(){
  ll ans = 1;
  for(int i = 0; i < v.size() && v[i] <= ans; ++i)
    ans += v[i];
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; ++i)  cin >> v[i];
    sort(v.begin(), v.end());
    cout << f() << "\n";
  }

  return 0;
}
