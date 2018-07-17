#include <bits/stdc++.h>
#define MAXN (1 << 20)

using namespace std;

int dp[MAXN], dv[MAXN], seq[MAXN], p[MAXN];

void precalc(){
  dp[1] = dv[1] = 1;
  for(int i = 2; i < 1000001; ++i){
    if(dv[i] == 0){
      dp[i] = 2;
      for(int j = 2*i; j < 1000001; j += i) dv[j] = i;
    }
  }
  return;
}

int f(int n){
  if(dp[n] != 0) return dp[n];
  int n_ = n, cont = 1;
  for(; n_ % dv[n] == 0; n_ /= dv[n], ++cont);
  return cont*f(n_);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n = 0, a, b;
  seq[0] = 1;
  precalc();
  for(int i = 1; i < MAXN; ++i){
    seq[i] = seq[i - 1] + f(seq[i - 1]);
    if(seq[i] > 1000000)  break;
  }
  for(int i = 1; i < 1000001; ++i){
    p[i] = p[i - 1];
    if(i == seq[n]){
      ++n;
      ++p[i];
    }
  }
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a >> b;
    cout << "Case " << i << ": " << p[b] - p[a - 1] << "\n";
  }

  return 0;
}
