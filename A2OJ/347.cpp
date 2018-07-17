#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  double a, b, c, ans;
  cin >> a >> b >> c;
  ans = sqrt(b*b - 4*a*c);
  ans -= b;
  ans /= (2.0*a);
  cout << ans << "\n";



  return 0;
}
