#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans;
  while(1){
    ans = 0;
    cin >> n;
    if(n == 0)  break;
    while(n){
      if(n%3 == 0){
        ans += n/3;
        n /= 3;
      }
      else if(n%3 == 2){
        n += 1;
        ans += n/3;
        n /= 3;
        n -= 1;
      }
      else if(n > 3){
        n += 2;
        ans += n/3;
        n /= 3;
        n -= 2;
      }
      else  n = 0;
    }
    cout << ans << "\n";
  }

  return 0;
}
