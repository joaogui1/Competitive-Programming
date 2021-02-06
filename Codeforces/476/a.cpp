#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, ans;
  cin >> n >> m;
  ans = (n + 1)/2 + ((m - ((n + 1)/2)%m)%m);
  if(ans > n) cout << "-1\n";
  else  cout << ans << "\n";
  return 0;
}
