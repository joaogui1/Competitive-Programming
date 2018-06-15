#include <bits/stdc++.h>
#define MOD 303700049LL

using namespace std;
typedef long long int lli;
typedef pair <lli, lli> pll;

lli G[100][110][110], vec[2][110];

pll f(lli x, int n){
  x -= (n - 1);
  for(lli i = 0; i < 62; ++i){
    if(x&(1LL << i)){
      for(int j = 0; j < n; ++j){
        vec[1][j] = 0LL;
        for(int k = 0; k < n; ++k)
          vec[1][j] = vec[1][j] + vec[0][k]*G[i][j][k];

      }
      //for(int j = 0; j < n; ++j)  cout << vec[1][j] << " \n"[j == n - 1];
      for(int j = 0; j < n; ++j)  vec[0][j] = vec[1][j]%MOD;
    }
  }
  return pll(vec[0][0], vec[0][n - 1]);
}

int main(){
  int n;
  lli kk;
  pll ans;
  while(scanf("%d %lld", &n, &kk) != EOF){
    memset(G, 0, sizeof G);
    memset(vec, 0, sizeof vec);

    for(int i = 1; i <= n; ++i)   cin >> vec[0][i];
    for(int i = 1; i <= n; ++i)   vec[0][0] += vec[0][i];
    for(int i = 1; i < n + 1; ++i)  G[0][0][i] = G[0][n][i] = n - i + 1;
    G[0][0][0] = 1;
    for(int i = 1; i < n; ++i) G[0][i][i + 1] = 1;

    for(int q = 0; q < 62; ++q)
      for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j){
          for(int k = 0; k <= n; ++k)
            G[q + 1][i][j] = (( G[q + 1][i][j] + G[q][i][k]*G[q][k][j]));
          G[q + 1][i][j] %= MOD;
        }

    ans = f(kk, n + 1);
    printf("%lld %lld\n", ans.second, ans.first);
  }




  return 0;
}
