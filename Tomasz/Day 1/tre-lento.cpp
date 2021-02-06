#include <bits/stdc++.h>

using namespace std;
int v[512], w[512];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> v[i];
    w[i] = 1 - v[i];
    v[i] += v[i - 1];
    w[i] += w[i - 1];
  }

  for(int i = 1; i <= n; ++i)
    for(int j = i; j <= n; ++j)
      for(int k = j + 1; k <= n; ++k){
        if(2*(w[j] - w[i - 1]) > j - i + 1 && 2*(v[k] - v[j]) > k - j)
          ans = max(ans, k - i + 1);
      }
  cout << ans << "\n";

  return 0;
}
