#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100100], ans;
int mark[100100], c[100100], dp[100100];

int f(int u){
  int v;
  mark[u] = 1;
  dp[u] = c[u];
  for(int i = 0; i < adj[u].size(); ++i){
    v = adj[u][i];
    if(!mark[v])  dp[u] += f(v);
  }
  return dp[u];
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b, d;
  cin >> n;
  for(int i = 1; i < n; ++i){
    cin >> a >> b >> d;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if(d == 2)  c[a] = c[b] = 1;
  }
  f(1);
  for(int i = 1; i <= n; ++i)
    if(dp[i] == 1)
      ans.push_back(i);
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " \n"[i + 1 == ans.size()];

  return 0;
}
