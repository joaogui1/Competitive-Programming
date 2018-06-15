#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

string n, s;
ll dp[100100];

bool comp(int i, int j){
  if(i + 1 == n.size()){
    for(int k = 0; k <= i; ++k){
      if(n[k] > s[j + k]) return 1;
      if(n[k] < s[j + k]) return 0;
    }
    return 1;
  }
  return (n.size() > i + 1);
}

ll f(int x){
  if(x >= s.size()) return 1;
  if(dp[x] != -1) return dp[x];
  dp[x] = 0;
  for(int i = 0; i + x < s.size(); ++i){
    if(comp(i, x))  dp[x] = (dp[x] + f(i + x + 1))%MOD;
    else  break;
  }
  return dp[x];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for(int i = 0; i < 100100; ++i)
    if(i > s.size() || s[i] != '0')
      dp[i] = -1;
  cout << f(0) << "\n";
  return 0;
}
