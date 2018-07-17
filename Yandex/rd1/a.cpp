#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int p, a, b;
  cin >> p >> a >> b;
  if(b > p) cout << "-1\n";
  else cout << max(a + b, p) << "\n";




  return 0;
}
