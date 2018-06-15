#include <bits/stdc++.h>
#define INF (1 << 20)

using namespace std;

vector <int> coins;
int dp[1000110];

void initialize(){
  coins.clear();
  for(int i = 1; i < 1000110; ++i)  dp[i] = INF;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, t, val, aux, lim, sum;
  cin >> t;
  while(t--){
    sum = 0;
    lim = 101*10001;
    initialize();
    cin >> val >> n;
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
      cin >> aux;
      sum += aux;
      coins.push_back(aux);
      if(aux > val) lim = min(lim, aux);
    }
    lim = min(lim, sum);
    for(int j = 0; j < n; ++j)
      for(int i = lim; i >= 0; --i)
          dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);

    for(int i = val; ; ++i)
      if(dp[i] != INF){
        cout << i << " " << dp[i] << "\n";
        break;
      }

  }


  return 0;
}
