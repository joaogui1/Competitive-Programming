#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int n;
ll a[1000100], dp[1000100];

ll f(int x){
  if(x > n) return 0;
  if(dp[x] != -1)  return dp[x];
  if(a[x] > a[x + 1])
    return dp[x] = a[x] + f(x + 2);
  return dp[x] = max(a[x] + f(x + 2), a[x + 1] + f(x + 3));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll ans = 0, test = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  memset(dp, -1, sizeof dp);
  /*for(int i = 1; i <= n; ++i){
    if(a[i + 1] > a[i] + a[i + 2]){
      ans += a[i + 1];
      i = i + 2;
    }
    else{
      ans += a[i];
      ++i;
    }
  }*/
  /*for(int i = 1; i <= n; ++i){
    int a = 1, b = 1;
    test = v[i];
    while(i - a > 0|| b + i <= n){
      if(v[max(i - a, 0)] > v[min(n, b + i)]){
        test += v[i - a];
        ++a;
      }
      else{
        test += v[b + i];
        ++b;
      }
      ++a;
      ++b;
    }
    ans = max(ans, test);
    cout << ans << "\n";
  }*/

  //cout << ans << "\n";
  cout << f(1) << "\n";
  return 0;
}
