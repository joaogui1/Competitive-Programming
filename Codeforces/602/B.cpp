#include <bits/stdc++.h>

using namespace std;

int x[400100];

int main(){
  ios_base::sync_with_stdio(0);
  int n, delta = 0, beg = 0, ans = 0, ult[2] = {0};
  cin >> n;
  for(int i = 0; i < n; ++i)  cin >> x[i];
  for(int i = 1; i < n; ++i){

  }
  cout << ans << endl;
  ans = max(ans, n - beg);
  cout << ans << endl;




  return 0;
}
