#include <bits/stdc++.h>

using namespace std;

int a[1000100], b[1000100];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0, sum = 0, old = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for(int i = 1; i <= n; ++i){
    sum += b[i] - a[i];
    if(sum == 0){
      ans += i - old - 1;
      old = i;
    }
  }

  cout << ans << "\n";

  return 0;
}
