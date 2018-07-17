#include <bits/stdc++.h>

using namespace std;

int G[128][128];

void fw(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
  for(int i = 0; i < 128; ++i)  G[i][i] = 0;
  return;
}

void initialize(){
  for(int i = 0; i < 128; ++i)
    for(int j = 0; j < 128; ++j)
      if(i != j)
        G[i][j] = (1 << 28);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b, c, k;
  for(int t = 1; ; ++t){
    initialize();
    cin >> n >> m;
    if(n + m == 0)  return 0;
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> c;
      G[a][b] = G[b][a] = c;
    }
    fw(n);
    cin >> k;
    cout << "Instancia " << t << "\n";
    for(int i = 0; i < k; ++i){
      cin >> a >> b;
      cout << G[a][b] << "\n";
    }
    cout << "\n";
  }


  return 0;
}
