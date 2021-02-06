#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, test, ans = 0;
  string s;
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    test = 0;
    cin >> s;
    for(int j = 0; j < s.size(); ++j)
      if(s[j] == '4' || s[j] == '7')  ++test;
    if(test < k + 1)  ++ans;
  }
  cout << ans << "\n";
  return 0;
}
