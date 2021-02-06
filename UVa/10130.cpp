#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;
int dp[2020][50], ans, max_dp[50];
vector <pii> goods;

void initialize(){
  ans = 0;
  goods.clear();
  memset(dp, 0, sizeof dp);
  memset(max_dp, 0, sizeof max_dp);
  return;
}

int main(){
  int t, n, aux, auy;
  scanf("%d", &t);
  while(t--){
    initialize();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
      scanf("%d %d", &aux, &auy);
      goods.push_back(pii(aux, auy));
    }

    for(int i = 1; i <= 40; ++i)  if(i >= goods[0].second) dp[0][i] = goods[0].first;
    for(int i = 1; i < goods.size(); ++i){
      for(int j = 1; j <= 40; ++j){
        if(goods[i].second > j)  dp[i][j] = dp[i - 1][j];
        else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - goods[i].second] + goods[i].first);
      }
    }



    for(int i = 1; i <= 40; ++i)
      for(int j = 0; j < goods.size(); ++j)
        max_dp[i] = max(max_dp[i], dp[j][i]);


    scanf("%d", &aux);
    for(int i = 0; i < aux; ++i){
      scanf("%d", &auy);
      ans += max_dp[auy];
    }

    printf("%d\n", ans);
  }



  return 0;
}
