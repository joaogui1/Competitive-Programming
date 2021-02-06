#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  bool vdc = 1;
  string s, ans[2] = {"NO\n", "YES\n"};
  for(int i = 0; i < 8; ++i){
    cin >> s;
    for(int i = 0; i < 8; ++i)
      if(s[i] == s[(i + 1)%8])  vdc = 0;
  }
  cout << ans[vdc];
  return 0;
}
