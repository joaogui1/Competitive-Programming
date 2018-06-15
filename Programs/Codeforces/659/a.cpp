#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int a, b, n, ans;
  cin >> n >> a >> b;
  ans = ((a + b)%n + n)%n;
  if(ans == 0)  ans = n;
  cout << ans << "\n";


  return 0;
}
