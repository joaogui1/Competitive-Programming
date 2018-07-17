#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long int ans, v[3];
  cin >> v[0] >> v[1] >> v[2];
  sort(v, v + 3);
  ans = (v[0] + v[1] + v[2])/3;
  ans = min(ans, v[0] + v[1]);
  cout << ans << "\n";

  return 0;
}
