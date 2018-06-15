#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  double a, b, c, d, r, q, ans, one;
  one = 1.0;
  cin >> a >> b >> c >> d;
  r = a/b, q = c/d;
  ans = r/(one - (one - r)*(one - q));
  cout << fixed << setprecision(12) << ans << "\n";



  return 0;
}
