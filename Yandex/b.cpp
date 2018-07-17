#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, idx;
  double v, t_p, best = (1 << 30) + 0.5, test, t, x;
  cin >> v >> t_p >> n;
  for(int i = 1; i <= n; ++i){
    cin >> x >> t;
    test = x + v*(t_p + t);
    if(test < best){
      idx = i;
      best = test;
    }
  }
  cout << fixed << setprecision(5) << best << " " << idx << "\n";

  return 0;
}
