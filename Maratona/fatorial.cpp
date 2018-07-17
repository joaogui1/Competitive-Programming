#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
//o fat maximo eh 8
int fat[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dp[1 << 17];
int main(){
   ios_base::sync_with_stdio(0);
   int n;
   cin >> n;
   for(int i = 2; i < (1 << 17); ++i)  dp[i] = (1 << 17);
   dp[1] = 1;
   for(int i = 2; i <= n; ++i)
      for(int j = 1; j < 9; ++j)
         if(i - fat[j] >= 0 && dp[i - fat[j]] != (1 << 17))  dp[i] = min(dp[i], dp[i - fat[j]] + 1);
   cout << dp[n] << "\n";
   return 0;
}
