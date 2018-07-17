#include <bits/stdc++.h>
#define INF 24
#define MINF (1 << 23)

using namespace std;

int dp[MINF + 10];

int f(int mask){
  if(dp[mask] != INF) return dp[mask];
  int aux = mask, ans = 0;
  for(int i = 1; i <= mask; i <<= 1)
    if(i & mask)
      ++ans;
  dp[mask] = ans;
  //cout << dp[mask] << endl;

  for(int i = 1; i < mask; i <<= 1){
    aux = mask;
    if((i & mask) && (i << 1 & mask)){
      if((i << 2) < MINF && ((i << 2) & ~mask)){
        aux ^= i;
        aux ^= (i << 1);
        aux |= (i << 2);
        dp[mask] = min(dp[mask], f(aux));
        aux = mask;
      }

      if(i > 1 && ((i >> 1) & ~mask)){
        aux ^= i;
        aux ^= (i << 1);
        aux |= (i >> 1);
        dp[mask] = min(dp[mask], f(aux));
      }
    }
  }
  return dp[mask];
}

void initialize(){
  for(int i = 0; i < MINF + 10; ++i)  dp[i] = INF;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  string in;
  int n, mask;
  cin >> n;
  while(n--){
    cin >> in;
    mask = 0;
    initialize();
    for(int i = 0; i < in.size(); ++i)
      if(in[i] == 'o')
        mask |= (1 << i);
    f(mask);
    cout << dp[mask] << "\n";
  }

  return 0;
}
