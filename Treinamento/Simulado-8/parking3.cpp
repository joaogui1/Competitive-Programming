#include <bits/stdc++.h>

using namespace std;

int x[2048], mark[2048];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  char auc;
  int n, m, k, a, ans;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)  cin >> auc;
  for(int i = 1; i <= k; ++i){
    ans = 0;
    cin >> a >> a;
    mark[a] = 1;
    x[i] = a;
    sort(x, x + i + 1);
    for(int j = 1; j <= i; ++j) ans = max(ans, x[j] - x[j - 1] - 1);//, cout << ans << "\n";
    ans = max(ans, n - x[i]);
    // cout << "ok\n";
    for(int j = 2; j < n; ++j)  ans = max(ans, min(j, n + 1 - j) - mark[j]);//, cout << ans << "\n";
    cout << ans << "\n";
  }


  return 0;
}
