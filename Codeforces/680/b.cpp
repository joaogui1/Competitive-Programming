#include <bits/stdc++.h>

using namespace std;

int v[128];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, ans;
  cin >> n >> a;
  for(int i = 1; i <= n; ++i) cin >> v[i];
  ans = v[a];
  for(int i = 1; i < n; ++i){
    if(i + a > n && a - i > 0)  ans += v[a - i];
    else if(i + a <= n && a - i < 1)  ans += v[a + i];
    else  ans += 2*(v[a + i] == v[a - i])*v[a + i];
  }
  cout << ans << "\n";

  return 0;
}
