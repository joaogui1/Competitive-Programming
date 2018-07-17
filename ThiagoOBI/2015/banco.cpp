#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll dp[8][5010];
int coin[6] = {2, 5, 10, 20, 50, 100}, qtd[6];

ll f(int type, int val){
  if(val == 0)  return 1;
  if(type > 5 || val < 0)  return 0;
  if(dp[type][val] != -1) return dp[type][val];
  dp[type][val] = 0;
  for(int i = 0; i <= qtd[type]; ++i)
    dp[type][val] += f(type + 1, val - i*coin[type]);
  return dp[type][val];
}

int main(){
  ll s;
  scanf("%lld", &s);
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < 6; ++i)  scanf("%d", &qtd[i]);
  printf("%lld\n", f(0, s));

  return 0;
}
