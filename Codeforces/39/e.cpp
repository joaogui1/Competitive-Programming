#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll n, dp[32][10100];
string ans[2] = {"Masha", "Stas"};

int f(ll a, ll b){
  int ret = 0;
  ll comp = 1;
  if(dp[a][b] != -1)  return dp[a][b];
  for(int i = 0; i < b; ++i){
    comp *= a;
    if(comp >= n)  return 0;
  }
  if(f(a + 1, b) == 0)  return 1;
  if(f(a, b + 1) == 0)  return 1;
  return 0;
}

int main(){
  ll a, b;
  cin >> a >> b >> n;
  memset(dp, -1, sizeof dp);
  if(a == 1 && (1LL << b) >= n) cout << "Missing\n";
  else  cout << ans[f(a, b)] << "\n";

  return 0;
}
