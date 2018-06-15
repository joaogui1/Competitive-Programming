#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, m, ans = 0;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    ans += m/5;
    ans += ((m%5) + (i%5) >= 5);
  }
  cout << ans << "\n";
  return 0;
}
