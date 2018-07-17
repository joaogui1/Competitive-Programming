#include <bits/stdc++.h>

using namespace std;

int G[128][128];

void fw(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
  return;
}

void initialize(int n){
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j)
      G[i][j] = (1 << 29);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int c, s, q, c1, c2, d;

  cin >> c >> s >> q;
  for(int t = 1; (c || s || q); ++t){
    initialize(c);
    if(t > 1) cout << "\n";
    for(int i = 0; i < s; ++i){
      cin >> c1 >> c2 >> d;
      G[c1][c2] = G[c2][c1] = d;
    }
    fw(c);
    cout << "Case #" << t << "\n";


    for(int i = 0; i < q; ++i){
      cin >> c1 >> c2;
      if(G[c1][c2] < (1 << 29))cout << G[c1][c2] << "\n";
      else cout << "no path\n";
    }
    cin >> c >> s >> q;
  }

  return 0;
}
