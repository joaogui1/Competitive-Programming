#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
typedef pair <ll, int> pii;

ll dp[50100][6][20][6], dist[2][5], t;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, m, o, a, b, ans = 0, aux, dx, sum;
  cin >> k >> n >> m >> o;
  for(int i = 0; i < 50100/k; ++i)
    for(int j = 0; j < k; ++j)
      for(int l = 0; l < 18; ++l)
        for(int z = 0; z < k; ++z)  dp[i][j][l][z] = (1LL << 49);

  for(int i = 0; i < m; ++i){
    cin >> a >> b >> t;
    dp[a/k][a%k][0][b%k] = min(t, dp[a/k][a%k][0][b%k]);
  }

  for(int l = 1; (1 << l) <= n/k; ++l){
    for(int i = 0; i <= n/k; ++i){
      if(i + (1 << (l - 1)) > 50010)  continue;
      for(int j = 0; j < k; ++j){
        for(int z = 0; z < k; ++z)
          for(int y = 0; y < k; ++y)
          dp[i][j][l][z] = min(dp[i][j][l][z], dp[i][j][l - 1][y] + dp[i + (1 << (l - 1))][y][l - 1][z]);
      }
    }
  }

  for(int i = 0; i < o; ++i){
    sum = 0;
    cin >> a >> b;
    dx = b/k - a/k;
    for(int q = 0; q < 5; ++q)  dist[0][q] = (1LL << 49);
    dist[0][a%k] = 0;
    for(int e = 0; e < 18; ++e){
      if((1 << e)&dx){
        for(int q = 0; q < 5; ++q)  dist[1][q] = (1LL << 49);
        for(int f = 0; f < k; ++f)
          for(int g = 0; g < k; ++g)
            dist[1][f] = min(dist[1][f], dist[0][g] + dp[sum + a/k][g][e][f]);
        sum += (1 << e);
        for(int ii = 0; ii < 5; ++ii)  swap(dist[1][ii], dist[0][ii]);
      }
    }
    cout << ((dist[0][b%k] < (1LL << 43))?dist[0][b%k]:-1) << "\n";
  }



  return 0;
}
