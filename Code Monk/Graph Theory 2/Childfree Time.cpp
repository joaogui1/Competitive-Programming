#include <bits/stdc++.h>
#define ss second
#define ff first

using namespace std;
typedef long long int ll;
typedef pair<ll, int> pii;

ll dp[1 << 20], ans;
int in[1 << 20];
vector <pii> out[1 << 20];

ll f(int v){
  if(dp[v] != -1) return dp[v];
  if(out[v].size() == 0)  return dp[v] = 0;
  dp[v] = 0;
  for(pii const & e : out[v])
    dp[v] = max(dp[v], e.first + f(e.second));
  return dp[v];
}

void initialize(){
  ans = 0;
  memset(in, 0, sizeof in);
  for(int i = 0; i < (1 << 20); ++i)  dp[i] = -1;
  for(int i = 0; i < (1 << 20); ++i)  out[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  ll t;
  int r, p, r1, r2;
  initialize();
  cin >> r >> p;
  for(int i = 0; i < p; ++i){
    cin >> r1 >> r2 >> t;
    ++in[r1];
    out[r2].push_back(pii(t + 2, r1));
  }
  for(int i = 1; i <= r; ++i)
    if(in[i] == 0)  ans = max(ans, f(i));
  cout << ans << "\n";
  return 0;
}
