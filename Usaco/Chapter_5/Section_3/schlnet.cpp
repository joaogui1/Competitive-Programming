/*
ID: joaogui1
LANG: C++
TASK: schlnet
*/
#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int g[128][128], G[128][128], id[128], in[128], out[128], scc[128], numscc = 0;

bool comp(int a, int b){
  return in[a] > in[b];
}

bool pmoc(int a, int b){
  return out[a] > out[b];
}

void tc(int n){
  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        g[i][j] |= (g[i][k] && g[k][j]);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ifstream cin ("schlnet.in");
  ofstream cout ("schlnet.out");
  int n, a, ans = 0, x = 0, y = 0;
  cin >> n;
  for(int i = 1; i <= n; ++i) v.push_back(i);
  for(int i = 1; i <= n; ++i){
    g[i][i] = 1;
    while(cin >> a){
      if(a == 0)  break;
      g[i][a] = 1;
    }
  }
  tc(n);

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(g[i][j] && i != j) ++in[i], ++out[j];
  sort(v.begin(), v.end(), comp);
  for(int i = 0; i < v.size(); ++i){
    a = v[i];
    if(id[a] == 0){
      ++x;
      for(int j = 1; j <= n; ++j)
        if(g[a][j])
          id[j] = a;
    }
  }

  memset(id, 0, sizeof id);
  sort(v.begin(), v.end(), pmoc);
  for(int i = 0; i < v.size(); ++i){
    a = v[i];
    if(id[a] == 0){
      ++y;
      for(int j = 1; j <= n; ++j)
        if(g[j][a])
          id[j] = a;
    }
  }

  for(int i = 1; i <= n; ++i){
    if(scc[i] != 0)  continue;
    scc[i] = ++numscc;
    for(int j = 1; j <= n; ++j)
      if(g[i][j] && g[j][i])  scc[j] = scc[i];
  }

  /*for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if((scc[i] != scc[j]) && g[i][j])
        G[i][j] = 1;

  for(int i = 1; i <= numscc; ++i)
    for(int j = 1; j <= numscc; ++j)
      if(G[i][j]){
        ++in[j];
        ++out[i];
      }
  for(int i = 1; i <= numscc; ++i){
    x += (in[i] == 0);
    y += (out[i] == 0);
  }*/

  ans = max(x, y);
  if(numscc == 1)  ans = 0;
  cout << x << "\n" << ans << "\n";


  return 0;
}
