#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(0);
  ll n, ans;
  int t;

  cin >> t;
  while(t--){
    cin >> n;
    n /= 5LL;
    ans = 0LL;
    for(; n; n /= 5LL)  ans += n;
    cout << ans << "\n";
  }



  return 0;
}
