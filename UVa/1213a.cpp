#include <bits/stdc++.h>

using namespace std;

int dp[1200][16];
vector <int> prime;
bool is_comp[1200];

void setup(){
  is_comp[1] = 1;
  for(int i = 2; i < 1200; ++i){
    if(!is_comp[i]){
      prime.push_back(i);
      for(int j = 2*i; j < 1200; j += i)  is_comp[j] = 1;
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, p;
  setup();
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for(int q = 0; q < prime.size(); ++q){
    p = prime[q];
    for(int j = 1120; j >= p; --j)
        for(int i = 14; i > 0; --i)
          dp[j][i] += dp[j - p][i - 1];
      }


  while(1){
    cin >> n >> k;
    if(n == 0 && k == 0)  break;
    cout << dp[n][k] << "\n";
  }

  return 0;
}
