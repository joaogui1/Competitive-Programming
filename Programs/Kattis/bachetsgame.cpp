#include <bits/stdc++.h>

using namespace std;

int dp[1 << 20];
vector <int> moves;

int main(){
  int n, m;
  string ans[2] = {"Ollie wins\n", "Stan wins\n"};
  while(cin >> n >> m){
    moves.assign(m, 0);
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < m; ++i)  cin >> moves[i];
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j < m; ++j)
        if(i + moves[j] < n + 1)
          dp[i + moves[j]] |=  !dp[i];

    //for(int i = 0; i <= n; ++i) cout << dp[i] << " \n"[n == i];
    cout << ans[dp[n]];
  }


  return 0;
}
