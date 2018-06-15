#include <bits/stdc++.h>

using namespace std;

string a, b;
int p[1003][1003], dp[1003][1003];
int main(){
  ios_base::sync_with_stdio(0);
  int n, m, prev;
  cin >> n >> m >> a >> b;
  for(int i = 0; i < a.size(); ++i){
    prev = -1;
    for(int j = 0; j < b.size(); ++j){
      if(a[i] == b[j]) prev = j;
      p[i + 1][j + 1] = prev;
    }
  }
  for(int i = 1; i <= a.size(); ++i)
    dp[i][0] = 1;

  for(int i = 0; i <= b.size(); ++i)
    dp[0][i] = (1 << 10);

  for(int i = 1; i <= a.size(); ++i)
    for(int j = 1; j <= b.size(); ++j){
      if(p[i][j] == -1) dp[i][j] = 1;
      else
        dp[i][j] = min( 1 + dp[i - 1][p[i][j]], dp[i - 1][j]);
      }

  cout << dp[a.size()][b.size()] << "\n";
  return 0;
}
