#include <bits/stdc++.h>
#define ff first
#define ss second
#define INF 100000

using namespace std;
typedef pair<int, int> pii;

int dp[4][10010][128];
vector <pii> p[4][128];

int f(int cow, int t, int n){
  if(t < 0) return 0;
  if(dp[cow][t][n] != -1)  return dp[cow][t][n];
  dp[cow][t][n] = 0;
  for(int i = 0; i < p[cow][n].size(); ++i)
    dp[cow][t][n] |= f(cow, t - p[cow][n][i].ss, p[cow][n][i].ff);
  return dp[cow][t][n];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream fin ("meeting.in");
  ofstream fout ("meeting.out");
  int n, m, a, b, c, d, ans = 100000;
  fin >> n >> m;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < m; ++i){
    fin >> a >> b >> c >> d;
    p[0][b].push_back(pii(a, c));
    p[1][b].push_back(pii(a, d));
  }
  dp[0][0][1] = dp[1][0][1] = 1;
  for(int i = 0; i <= 10000; ++i) ans = min(ans, (f(0, i, n) && f(1, i, n))?i:INF);

  if(ans < INF) fout << ans << "\n";
  else  fout << "IMPOSSIBLE\n";
  return 0;
}
