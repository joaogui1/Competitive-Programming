#include <bits/stdc++.h>

using namespace std;

int dp[16][128][128];

int f(int e, int bot, int top){
  if(bot > top)  return 0;
  if(e == 1)  return (top*(top + 1))/2 - (bot*(bot - 1))/2;
  if(dp[e][bot][top] != 0)  return dp[e][bot][top];
  dp[e][bot][top] = (1 << 20);
  for(int i = bot; i <= top; ++i)
    dp[e][bot][top] = min(dp[e][bot][top], i + max(f(e - 1, bot, i - 1), f(e, i + 1, top)));
  return dp[e][bot][top];
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n;
  while(n--){
    cin >> k >> m;
    cout << f(k, 1, m) << "\n";
  }



  return 0;
}
