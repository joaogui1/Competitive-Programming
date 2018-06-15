#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int g[256][256];
vector <pii> l, c;

int main(){
  int n, m, aux, vdc = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      scanf("%d", &g[i][j]);
  while(!vdc){
    vdc = 1;
    for(int i = 1; i <= m; ++i){
      if((g[1][i] - 1)%m + 1 != i){
        c.push_back(pii((g[1][i] - 1)%m + 1, i));
        swap(g[1][i], g[1][(g[1][i] - 1)%m + 1]);
        vdc = 0;
        break;
      }
    }
  }
  vdc = 0;
  while(!vdc){
    vdc = 1;
    for(int i = 1; i <= n; ++i){
      if((g[i][1] - 1)/m + 1 != i){
        vdc = 0;
        l.push_back(pii((g[i][1] - 1)/m + 1, i));
        swap(g[i][1], g[(g[i][1] - 1)/m + 1][1]);
        break;
      }
    }
  }
  printf("%d\n", c.size() + l.size());
  for(int i = 0; i < l.size(); ++i)
    printf("L %d %d\n", l[i].ff, l[i].ss);
  for(int i = 0; i < c.size(); ++i)
    printf("C %d %d\n", c[i].ff, c[i].ss);

  return 0;
}
