#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int g[2][200100], lft[200100], rght[200100], both[200100], cnt = 1;

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
    lft[i] = lft[i - 1], rght[i] = rght[i - 1], both[i] = both[i - 1];
    if(g[0][i] && !g[0][i - 1]) ++lft[i];
    if(g[1][i] && !g[1][i - 1]) ++rght[i];
    if(!g[0][i - 1] && g[1][i - 1] && g[0][i] && g[1][i]) ++both[i];
  }
}

int colour(int ar, int ac, int br, int bc){
  int ans = 0;
  if(ar == br)
    if(ar == 1) ans = lft[bc] - lft[ac - 1] + (g[0][ac - 1]);
    else  ans = rght[bc] - rght[ac - 1] + (g[1][ac - 1]);
  else ans = both[bc] - both[ac - 1] + (g[0][ac - 1] && g[1][ac - 1]);

  return ans;
}
