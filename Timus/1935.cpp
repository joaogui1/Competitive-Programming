#include <bits/stdc++.h>

using namespace std;

int v[128];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> v[i];
  sort(v, v + n);
  for(int i = 0; i < n; ++i)  ans += v[i];
  ans += v[n - 1];
  cout << ans << "\n";
  return 0;
}
