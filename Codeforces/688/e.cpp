#include <bits/stdc++.h>

using namespace std;

int dp[1024][1024];
vector <int> ans;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, c;
  cin >> n >> k;
  dp[0][0] = 1;
  for(int i = 0; i < n; ++i){
    cin >> c;
    for(int j = k; j > -1; --j)
      for(int l = j + 1; l > -1; --l){
        dp[j + c][l] |= dp[j][l];
        dp[j + c][l + c] |= dp[j][l];
      }
  }

  for(int i = 0; i <= k; ++i)
    if(dp[k][i])
      ans.push_back(i);
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " \n"[i == ans.size() - 1];
  return 0;
}
