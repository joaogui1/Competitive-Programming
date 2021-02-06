#include <bits/stdc++.h>

using namespace std;

long long int dp[7500], coins[5] = {1, 5, 10, 25, 50};

int main(){
  ios_base::sync_with_stdio(0);
  int n;

  dp[0] = 1;
  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 7500; ++j)
      if(j >= coins[i]) dp[j] += dp[j - coins[i]];

  while(cin >> n){
    cout << dp[n] << "\n";
  }




  return 0;
}
