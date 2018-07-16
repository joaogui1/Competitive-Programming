#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int g[2][200100], l[200100], r[200100], both[200100], cnt = 1;

void init(int r, int c, int sr, int sc, int m, char* s){
  for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j)
      g[i][j] = 1;
  g[sr][sc] = 0;
  for(int i = 0; i < m; ++i){
    if(s[i] == 'N') --sr;
    if(s[i] == 'S') ++sr;
    if(s[i] == 'E') ++sc;
    if(s[i] == 'W') --sc;
    g[sr][sc] = 0;
  }
  for(int i = 1; i <= c; ++i){
    l[i] = l[i - 1], r[i] = r[i - 1], both[i] = both[i - 1];
    if(g[0][i] && !g[0][i - 1]) ++l[i];
    if(g[1][i] && !g[1][i - 1]) ++r[i];
    if(!g[0][i - 1] && g[1][i - 1] && g[0][i] && g[1][i]) ++both[i];
  }
}

int colour(int ar, int ac, int br, int bc){
  int ans = 0;
  if(ar == br == 1) ans = l[bc] - l[ac - 1] + (g[0][ac - 1]);
  else if(ar == br == 2) ans = r[bc] - r[ac - 1] + (g[1][ac - 1]);
  else ans = both[bc] - both[ac - 1] + (g[0][ac - 1] && g[1][ac - 1]);

  return ans;
}
