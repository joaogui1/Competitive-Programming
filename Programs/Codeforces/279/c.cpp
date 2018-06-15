#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

pii dp[100100];
int seq[100100], id[100100], righ[100100], num = 0, sq[100100];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> seq[i];
  for(int i = 1; i <= n; ++i){
    if(seq[i] != seq[i - 1])  righ[num++] = i - 1;
    id[i] = num;
    sq[num] = seq[i];
  }
  dp[num].ff = n;
  if(num > 1 && sq[num] > sq[num - 1])  dp[num].ss = 1; // cres
  else if(num > 1 && sq[num] < sq[num - 1]) dp[num].ss = 2; // dec
  for(int i = num - 1; i > 0; --i){
    if(sq[i] < sq[i + 1]) dp[i].ff = dp[i + 1].ff, dp[i].ss = 1; // crescente
    else{ //dec
      dp[i].ss = 2;
      if(dp[i + 1].ss > 1) dp[i].ff = dp[i + 1].ff;
      else  dp[i].ff = righ[i + 1];
    }
  }
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    if(dp[id[a]].ff >= b) cout << "Yes\n";
    else  cout << "No\n";
  }
  return 0;
}
