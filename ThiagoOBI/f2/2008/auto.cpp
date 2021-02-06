#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  string in;
  cin >> n;
  cin >> in;
  for(int i = 0; i < n; ++i)
    ans += (in[i] == 'P' || in[i] == 'C') + (in[i] != 'D');
  cout << ans << "\n";




  return 0;
}
