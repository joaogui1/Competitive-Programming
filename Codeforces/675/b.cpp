#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll G[3][3], n;

int f(){
  ll sum[4] = {0};
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      if(G[i][j]  < 1 || G[i][j] > n)  return 0;
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      sum[0] += G[i][j];

  for(int i = 1; i < 3; ++i)
    for(int j = 0; j < 2; ++j)
      sum[1] += G[i][j];

  for(int i = 0; i < 2; ++i)
    for(int j = 1; j < 3; ++j)
      sum[2] += G[i][j];

  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      sum[3] += G[i][j];

  return (sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3]);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll a, b, c, d, ans = 0;
  cin >> n >> a >> b >> c >> d;
  G[1][1] = 1;
  G[0][1] = a, G[1][0] = b, G[1][2] = c, G[2][1] = d;
  for(int i = 1; i <= n; ++i){
    G[0][0] = i;
    G[0][2] = G[0][0] + b - c;
    G[2][0] = G[0][0] + a - d;
    G[2][2] = G[2][0] + b - c;
    ans += n*f();
  }
  cout << ans << "\n";
  return 0;
}
