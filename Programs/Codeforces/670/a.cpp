#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, ans = 0;
  cin >> n;
  k = n;
  while(k > 0){
    k -= 5;
    if(k < 0) break;
    ans += min(k, 2);
    k -= 2;
  }
  cout << ans << " ";
  k = n;
  ans = 0;
  while(k > 0){
    ans += min(k, 2);
    k -= 7;
    if(k < 0) break;
  }
  cout << ans << "\n";

  return 0;
}
