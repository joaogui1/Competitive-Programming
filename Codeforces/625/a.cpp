#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, a, b, c, ans;
  cin >> n >> a >> b >> c;
  ans = n/a;
  if(n >= b)  ans = max(ans, (n - c)/(b - c) + (n - ((n - c)/(b - c))*(b - c))/a);
  if(n >= b)  ans = max(ans, (n - b + 1)/(b - c));
  //cout << (n - b) << " " << (b - c) << " " <<  b/a << endl;
  cout << ans << "\n";


  return 0;
}
