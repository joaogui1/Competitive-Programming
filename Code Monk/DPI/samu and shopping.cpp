#include <bits/stdc++.h>
#define INF (1LL << 33)

using namespace std;
typedef long long int ll;

int n;
ll dp[100010][8], cost[100010][8];

ll f(int idx, int forb){
  if(idx > n - 1) return 0;
  if(dp[idx][forb] != INF) return dp[idx][forb];

  for(int i = 0; i < 3; ++i)
    if(i != forb) dp[idx][forb] = min(f(idx + 1, i) + cost[idx][i], dp[idx][forb]);
  return dp[idx][forb];
}

ll f(){
  ll ans = INF;
  for(int i = 0; i < 3; ++i)
    ans = min(f(1, i) + cost[0][i], ans);
  return ans;
}

void initialize(){
  for(int i = 0; i < 100010; ++i)
    for(int j = 0; j < 3; ++j)
      dp[i][j] = INF;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    initialize();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < 3; ++j)
        cin >> cost[i][j];

    cout << f() << "\n";
  }


  return 0;
}
