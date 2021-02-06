#include <bits/stdc++.h>

using namespace std;

long long int dp[30100], coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main(){
  int aux, auy;
  double n;

  dp[0] = 1;
  for(int j = 0; j < 11; ++j)
    for(int i = 1; i < 30100; ++i)
        if(i >= coins[j]) dp[i] += dp[i - coins[j]];

  while(1){
    scanf("%lf", &n);
    //cout << n << " " << 100*n <<  endl;
    if(n == 0.00) return 0;
    aux = (ceil(100*n));
    auy = (floor(100*n));
    if(100*n - auy < aux - 100*n) aux = auy;
    //cout << aux << endl;
    printf ("%6.2lf%17lld\n", n, dp[aux]);
  }



  return 0;
}
