#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, d, test = 0, ans = 0;
  bool vdc;
  string s[128];
  cin >> n >> d;
  for(int i = 0; i < d; ++i)  cin >> s[i];
  for(int i = 0; i < d; ++i){
    vdc = 1;
    for(int j = 0; j < n; ++j)  vdc &= (s[i][j] == '1');
    if(!vdc)  ++test;
    if(vdc) test = 0;
    ans = max(ans, test);
  }

  cout << ans << "\n";
  return 0;
}
