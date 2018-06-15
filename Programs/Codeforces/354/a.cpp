#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll w[100100], q[4], c[4];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  ll l, r, ans = 0, test = 0, aux;
  cin >> n >> l >> r >> q[0] >> q[1];
  for(int i = 1; i <= n; ++i)  cin >> w[i];
  for(int i = 1; i <= n; ++i)  ans += l*w[i];
  test = ans;
  ans += (n - 1)*q[0];
  c[1] = 1;
  c[0] = n - 1;
  for(int i = n; i > 0; --i, --c[0], ++c[1]){
    test -= w[i]*l;
    test += w[i]*r;
    aux = test + max(abs(c[0] - c[1]) - 1, 0LL)*q[c[0] <  c[1]];
    ans = min(aux, ans);
  }
  cout << ans << "\n";
  return 0;
}
