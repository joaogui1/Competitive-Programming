#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(0);
  ll a, mod, ans = 0;
  string days;
  cin >> a >> mod >> days;
  for(int i = 0; i < days.size(); ++i, a *= a){
    if(a >= mod)  a %= mod;
    if(days[i] == '1')  ans += a;
    if(ans >= mod)  ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
