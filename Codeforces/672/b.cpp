#include <bits/stdc++.h>

using namespace std;

int freq[32];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  string s;
  cin >> n >> s;
  for(int i = 0; i < s.size(); ++i) ++freq[s[i] - 'a'];
  if(n > 26)  cout << -1 << "\n";
  else{
    for(int i = 0; i < 26; ++i) ans += max(0, freq[i] - 1);
    cout << ans << "\n";
  }

  return 0;
}
