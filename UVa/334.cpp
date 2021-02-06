#include <bits/stdc++.h>

using namespace std;
typedef pair <string, string> pss;

int G[128][128], cont;
map <string, int> mapa;
map <int, string> _mapa;
vector < pss > ans;

void fw(int n){
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        G[i][j] |= (G[i][k] & G[k][j]);

  return;
}

void initialize(int n){
  cont = 0;
  ans.clear();
  mapa.clear();
  _mapa.clear();
  memset(G, 0, sizeof G);
  for(int i = 0; i < n; ++i)  G[i][i] = 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, t = 0;
  string aus, aur;
  while(1){
    cin >> n;
    initialize(n);
    if(n == 0)  return 0;

    for(int i = 0; i < n; ++i){
      cin >> m;
      cin >> aus;
      if(mapa.count(aus) == 0){
        mapa[aus] = cont;
        _mapa[cont++] = aus;
      }
      for(int i = 1; i < m; ++i){
        cin >> aur;
        if(mapa.count(aur) == 0){
          mapa[aur] = cont;
          _mapa[cont++] = aur;
        }
        G[mapa[aus]][mapa[aur]] = 1;
        aus = aur;
      }
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
      cin >> aus >> aur;
      G[mapa[aus]][mapa[aur]] = 1;
    }
    fw(cont);

    //for(int i = 0; i < cont; ++i)
      //for(int j = 0; j < cont; ++j)
        //cout << G[i][j] << " \n"[j == cont - 1];

    cout << "Case " << ++t << ", ";
    for(int i = 0; i < cont; ++i)
      for(int j = 0; j < i; ++j)
        if(!(G[i][j] || G[j][i]))
          ans.push_back(pss(_mapa[i], _mapa[j]));

    if(ans.size() == 0){
      cout << "no concurrent events.\n";
      continue;
    }

    cout << ans.size() << " concurrent events:\n";
    for(int i = 0; i < 2 && i < ans.size(); ++i){
      cout << "(" << ans[i].first << ", " << ans[i].second << ") ";
    }
    cout << "\n";

  }
  return 0;
}
