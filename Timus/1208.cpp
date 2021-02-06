#include <bits/stdc++.h>

using namespace std;

string s[32][4];
int dp[1 << 20], forbid[32], n, ans;

int f(int persona){
  int shadow;
  for(int i = n - 1; i > -1; --i){
    if(persona&(1 << i) != 0) break;
    if((persona&forbid[i]) == 0){
      shadow = persona|(1 << i);
      if(dp[shadow] != 0) continue;
      dp[shadow] = 1 + dp[persona];
      ans = max(dp[shadow], ans);
      f(shadow);
    }
  }
  return ans;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 3; ++j)
      cin >> s[i][j];
    sort(s[i], s[i] + 3);
  }
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int k = 0; k < 3; ++k)
        for(int l = 0; l < 3; ++l)
          if(s[i][k] == s[j][l])
            forbid[i] |= (1 << j);
  cout << f(0) << "\n";



  return 0;
}
