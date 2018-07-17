#include <bits/stdc++.h>

using namespace std;

int g[110][110], op[10100], r[10100], c[10100], x[10100], v[110];

int main(){
  //ios_base::sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;


  for(int i = 0; i < q; ++i){
    cin >> op[i] >> r[i];
    --r[i];
    if(op[i] == 3)  cin >> c[i] >> x[i];
    --c[i];
  }
  for(int i = q - 1; i > -1; --i){
    if(op[i] == 3)
      g[r[i]][c[i]] = x[i];
    else if(op[i] == 1){
      for(int j = 0; j < m; ++j)
        v[j] = g[r[i]][(j + m - 1)%m];
      for(int j = 0; j < m; ++j)  g[r[i]][j] = v[j];
    }

    else{
      for(int j = 0; j < n; ++j)
        v[j] = g[(j + n - 1)%n][r[i]];
      for(int j = 0; j < n; ++j)  g[j][r[i]] = v[j];
    }
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cout << g[i][j] << " \n"[j == m - 1];

  return 0;
}
