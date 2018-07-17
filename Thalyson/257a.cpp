#include <bits/stdc++.h>

using namespace std;

int a[64];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i)  cin >> a[i];
  sort(a, a + n);
  if(k >= m) n = -1;
  for(int i = n - 1; i > -1; --i){
    k += a[i] - 1;
    ++ans;
    if(k >= m)  break;
    if(ans == n){
      cout << "-1\n";
      return 0;
    }
  }
  cout << ans << "\n";

  return 0;
}
