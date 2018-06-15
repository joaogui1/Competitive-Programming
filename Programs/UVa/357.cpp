#include <bits/stdc++.h>

using namespace std;

long long int dp[30010], coins[5] = {1, 5, 10, 25, 50};

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  dp[0] = 1;
  for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 30001; ++j)
      if(j >= coins[i]) dp[j] += dp[j - coins[i]];

  while(cin >> n){
    if(dp[n] == 1)  cout << "There is only 1 way to produce " << n << " cents change.\n";
    else  cout << "There are " << dp[n] << " ways to produce " << n<< " cents change.\n";
  }


  return 0;
}
