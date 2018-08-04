#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int h[128];
ll dp[128][128][1024][3];
static ll MOD = 1000000007;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, l, aux;
  cin >> n >> l;
  for(int i = 0; i < n; ++i)  cin >> h[i];
  sort(h, h + n);
  if(n == 1){
    cout << 1 << "\n";
    return 0;
  }

  h[n] = (1 << 15);
  if(a[1] - a[0] <= l)  dp[1][1][h[1] - h[0]][1] = 2;
  if(2*(a[1] - a[0]) <= l)  dp[1][1][2*(a[1] - a[0])][0] = 1;

  for(int i = 1; i < n; ++i){
    aux = a[i + 1] - a[i];
    for(int j = 1; j <= i; ++j){
      for(int k = 0; k <= l; ++k){
        for(int m = 0; m < 3; ++m){
          if(!dp[i][j][k][m]) continue;
          //primeiro tentamos preencher um dos fins
          if(m < 2 && k + aux*(2*j - m - 1) <= l){
            if(i == n - 1)
          }
        }
      }
    }

  }

  return 0;
}
