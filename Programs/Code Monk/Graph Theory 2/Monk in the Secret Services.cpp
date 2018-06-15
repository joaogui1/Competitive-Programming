#include <bits/stdc++.h>

using namespace std;

int G[110][110], ans;

void fw(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  return;
}

void initialize(){
  ans = 0;
  for(int i = 0; i < 110; ++i)
    for(int j = 0; j < 110; ++j)
      G[i][j] = 1 << 29;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, m, aux, auy, c, s, a, h;
  cin >> t;
  while(t--){
    cin >> n >> m;
    initialize();
    for(int i = 0; i < m; ++i){
      cin >> aux >> auy >> c;
      G[aux][auy] = min(G[aux][auy], c);
      G[auy][aux] = G[aux][auy];
    }

    fw(n);
    for(int i = 1; i <= n; ++i) G[i][i] = 0;
    cin >> s >> a >> h;
    for(int i = 1; i <= n; ++i)
      if(i != a && i != s && i != h)
        ans = max(ans, G[s][i] + G[i][a] + G[a][i] + G[i][h]);
    cout << ans << "\n";
  }



  return 0;
}
