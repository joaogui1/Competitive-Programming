#include <bits/stdc++.h>

using namespace std;

string ans[2] = {"NO", "YES"};
int g[128][128], mark[128][128], dx[4] = {1, 1, 1, 2}, dy[4] = {-1, 0, 1, 0};

bool prop(int x, int y){
  bool vdc = 1;
  for(int i = 0; i < 4; ++i)
    vdc &= (g[x + dx[i]][y + dy[i]] && !mark[x + dx[i]][y + dy[i]]);
  if(vdc == 0)  return 0;
  for(int i = 0; i < 4; ++i)
    mark[x + dx[i]][y + dy[i]] = 1;
  return 1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  char auc;
  bool vdc = 1;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
      cin >> auc;
      g[i][j] = (auc == '#');
    }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(g[i][j] && !mark[i][j])
        vdc &= prop(i, j);

  cout << ans[vdc] << "\n";
  return 0;
}
