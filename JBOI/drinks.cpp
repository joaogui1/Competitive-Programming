#include <bits/stdc++.h>
#define ff first
#define ss second
#define oo (1LL << 50)

using namespace std;
typedef long long int ll;
typedef pair<ll, int> pil;

ll dr[2][128];
vector <int> v[2];
ll dp[128][128][128];

ll f(int a, int b, int n){
  //if(n == 0 && a == b) return 0;
  if(n == 0 && a != b) return oo;
  if(dp[a][b][n] != -oo) return dp[a][b][n];
  dp[a][b][n] = f(a + 1, b, n - 1) + dr[0][n];
  if(abs(dp[a][b][n]) > abs(f(a, b + 1, n - 1) - dr[1][n]))
    dp[a][b][n] = f(a, b + 1, n - 1) - dr[1][n];
  cout << a << " " << b << " " << n << " " << dp[a][b][n] << "\n";
  return dp[a][b][n];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, aux;
  ll acc = 0;
  cin >> n;
  for(int i = 0; i < 128; ++i)
    for(int j = 0; j < 128; ++j)
      for(int k = 0; k < 128; ++k)
        dp[i][j][k] = -oo;
  for(int i = 1; i <= n; ++i)
    cin >> dr[0][i] >> dr[1][i];
  cout << f(0, 0, n) << "\n";

  return 0;
}
