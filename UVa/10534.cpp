#include <bits/stdc++.h>

using namespace std;

int dp[4][100100];
vector <int> lis, v;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  while(cin >> n){
    ans = 0;
    lis.clear();
    v.assign(n, 0);
    memset(dp, 0, sizeof dp);
    vector<int>::iterator it;
    for(int i = 0; i < n; ++i)  cin >> v[i];

    for(int i = 0; i < n; ++i){
      it = lower_bound(lis.begin(), lis.end(), v[i]);
      if(it == lis.end()){
        lis.push_back(v[i]);
        dp[0][i] = lis.size();
      }
      else{
        *it = v[i];
        dp[0][i] = (it - lis.begin()) + 1;
      }
    }
    lis.clear();

    for(int i = n - 1; i > -1; --i){
      it = lower_bound(lis.begin(), lis.end(), v[i]);
      if(it == lis.end()){
        lis.push_back(v[i]);
        dp[1][i] = lis.size();
      }
      else{
        *it = v[i];
        dp[1][i] = (it - lis.begin()) + 1;
      }
    }
    for(int i = 0; i < n; ++i)  ans = max(ans, 2*min(dp[0][i], dp[1][i]) - 1);
    cout << ans << "\n";
  }
  return 0;
}
