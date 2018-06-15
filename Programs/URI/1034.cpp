#include <bits/stdc++.h>
#define INF (1 << 29)

using namespace std;

int dp[1000100];
vector <int> c;

int main(){
  ios_base::sync_with_stdio(0);
  int n, k, t;
  cin >> t;
  while(t--){
    cin >> k >> n;
    c.assign(k, 0);
    for(int i = 0; i < n + 10; ++i) dp[i] = INF;
    for(int i = 0; i < k; ++i)  cin >> c[i];
    dp[0] = 0;

    for(int i = 0; i < k; ++i)
      for(int j = 0; j <= n - c[i]; ++j)
        if(dp[j] != INF) dp[j + c[i]] = min(dp[j] + 1, dp[j + c[i]]);
    cout << dp[n] << "\n";
  }




  return 0;
}
