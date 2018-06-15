#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

queue <pii> A[2048], B[2048];
int s[2048][2048], dp[2048][2048], t[2048];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, b;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> t[i];

  for(int i = 1; i <= n; ++i) s[i][i] = i;

  for(int l = 0; l < n; ++l){
    for(int a = 1; a <= n - l; ++a){
      b = a + l;
      for(int i = s[a][b - 1]; i <= s[a + 1][b]; ++i)
        if(dp[a][i - 1] <= dp[i + 1][b])
          s[a][b] = i;
      A[a].push(pii(b, t[b] + dp[a][b - 1]));
      while(A[a].front().ff <= s[a][b])
        A[a].pop();
      B[b].push(pii(a, t[a] + dp[a + 1][b]));
      while(B[b].front().ff > s[a][b])
        B[b].pop();
      dp[a][b] = min(B[b].front().ss, A[a].front().ss);
    }
  }

  cout << dp[1][n] << "\n";
  return 0;
}
