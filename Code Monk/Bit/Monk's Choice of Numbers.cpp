#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int ones(int a){
  int ret;
  for(ret = 0; a > 0; a -= a&-a, ++ret);
  return ret;
}

bool comp(int a, int b){
  return ones(a) > ones(b);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, t, ans;
  cin >> t;
  while(t--){
    cin >> n >> k;
    ans = 0;
    v.assign(n, 0);
    for(int i = 0; i < n; ++i)  cin >> v[i];

    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < k; ++i) ans += ones(v[i]);
    cout << ans << "\n";

  }



  return 0;
}
