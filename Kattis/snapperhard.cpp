#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, k;
  bool vdc;
  string ans[2] = {"OFF\n", "ON\n"};
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cin >> n >> k;
    vdc = (k & ((1LL << n) - 1)) == (1 << n) - 1;
    cout << "Case #" << i << ": " << ans[vdc];

  }


  return 0;
}
