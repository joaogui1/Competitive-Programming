#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   int dp[60][60], ans;
   string a, b;
   while(getline(cin, a)){
      getline(cin, b);
      ans = 0;
      memset(dp, 0, sizeof dp);
      for(int i = 0; i < a.size(); ++i)
         for(int j = 0; j < b.size(); ++j)
            dp[i][j] = (a[i] == b[j])?((i != 0 && j != 0)*dp[i - 1][j - 1] + 1):(0), ans = max(ans, dp[i][j]);
      cout << ans << "\n";
   }
   return 0;
}
