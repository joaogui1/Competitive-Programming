#include <bits/stdc++.h>

using namespace std;

int v[100];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  v[n + 1] = 90;
  for(int i = 1; i <= n; ++i)  cin >> v[i];
  for(int i = 1; i <= n + 1; ++i){
    if(v[i] - v[i - 1] <= 15) ans = v[i];
    else{
      ans += 15;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
