#include <bits/stdc++.h>

using namespace std;

int dp[1200][1200][20];
vector <int> prime;
bool is_comp[1200];

void setup(){
  for(int i = 0; i < 1200; ++i)
    for(int j = 0; j < 1200; ++j)
      for(int k = 0; k < 20; ++k)
        dp[i][j][k] = -1;
  is_comp[1] = 1;
  for(int i = 2; i < 1200; ++i){
    if(!is_comp[i]){
      prime.push_back(i);
      for(int j = 2*i; j < 1200; j += i)  is_comp[j] = 1;
    }
  }
  return;
}

int f(int n, int p, int k){
  if(n < 0 || k < 0) return 0;
  if(n > 0 && k == 0) return 0;
  if(n == 0 && k > 0) return 0;
  if(n == 0 && k == 0)  return 1;
  if(dp[n][p][k] != -1) return dp[n][p][k];
  if(p <= 0)  return dp[n][p][k] = 0;
  dp[n][p][k] = 0;
  for(int i = 0; i < p; ++i)
    dp[n][p][k] += f(n - prime[i], i, k - 1);
  return dp[n][p][k];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k;
  setup();

  while(1){
    cin >> n >> k;
    if(n == 0 && k == 0)  break;
    cout << f(n, prime.size(), k) << "\n";
  }

  return 0;
}
