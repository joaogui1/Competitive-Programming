#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll cont[100010], dp[100010];
ll f(int n){
  if(dp[n] != -1) return dp[n];
  if(cont[n] == 0)  return dp[n] = f(n - 1);
  return dp[n] = max(f(n - 1), f(n - 2) + cont[n]*n);
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, s = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a;
    ++cont[a];
    s = max(s, a);
  }
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  cout << f(s) << "\n";


  return 0;
}
