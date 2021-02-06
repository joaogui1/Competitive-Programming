#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int dp[4][10100];
set <string> ans;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  string s;
  cin >> s;
  n = s.size();
  dp[0][n - 1] = dp[1][n - 1] = 1;
  for(int i = n - 2; i > 3; --i){
    dp[0][i] = dp[1][i + 2] || (dp[0][i + 2] && s.substr(i + 1, 2) != s.substr(i + 3, 2));
    dp[1][i] = dp[0][i + 3] || (dp[1][i + 3] && s.substr(i + 1, 3) != s.substr(i + 4, 3));
  }
  for(int i = n - 2; i > 3; --i){
    if(dp[0][i])  ans.insert(s.substr(i + 1, 2));
    if(dp[1][i])  ans.insert(s.substr(i + 1, 3));
  }
  cout << ans.size() << "\n";
  for(; ans.size(); ans.erase(ans.begin())) cout << *ans.begin() << "\n";
  return 0;
}
