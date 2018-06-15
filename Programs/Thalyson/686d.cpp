#include <bits/stdc++.h>

using namespace std;

vector <int> ch[300300];
int p[300300], sz[300300], bigc[300300], cen[300300];

int dfs(int u){
  int v;
  sz[u] = 1;
  bigc[u] = -1;
  for(int i = 0; i < ch[u].size(); ++i){
    v = ch[u][i];
    sz[u] += dfs(v);
    if(bigc[u] == -1 || sz[v] > sz[bigc[u]])  bigc[u] = v;
  }
  if(bigc[u] == -1) bigc[u] = u;

  return sz[u];
}


int f(int u){
  int v = u;
  if(cen[u] != 0) return cen[u];
  if(ch[u].size() == 0) return cen[u] = u;
  for(int i = 0; i < ch[u].size(); ++i){
    v = ch[u][i];
    if(v == 0) return 0;
    f(v);
  }
  for(v = cen[bigc[u]]; sz[v] < (sz[u] + 1)/2 || sz[bigc[v]] > sz[u]/2; v = p[v]);
  return cen[u] = v;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, q, a;
  cin >> n >> q;
  for(int i = 2; i <= n; ++i){
    cin >> a;
    p[i] = a;
    ch[a].push_back(i);
  }
  dfs(1);

  for(int i = 0; i < q; ++i){
    cin >> a;
    cout << f(a) << "\n";
  }




  return 0;
}
