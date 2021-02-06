#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  string s;
  cin >> n;
  cin >> s;
  for(int i = 0; i < s.size() - 1; ++i){
    if(s[i] == s[i + 1])  ++ans;
  }
  cout << ans << "\n";
  return 0;
}
