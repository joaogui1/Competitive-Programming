#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(0);
  ll t, k, c, s, block;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cin >> k >> c >> s;
    block = pow(k, c - 1);
    cout << "Case #" << i << ": ";
    if(c == 1 && s < k){
      cout << "IMPOSSIBLE\n";
      continue;
    }
    if(c == 1){
      for(int i = 1; i <= k; ++i) cout << i << " \n"[i == k];
      continue;
    }
    if(s < k - 1){
      cout << "IMPOSSIBLE\n";
      continue;
    }
    if(k == 1){
      cout << 1 << "\n";
      continue;
    }
    for(int i = 2; i <= k; ++i)
      cout << i << " \n"[i == k];
  }

  return 0;
}
