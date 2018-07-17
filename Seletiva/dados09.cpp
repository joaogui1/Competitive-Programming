#include <bits/stdc++.h>

using namespace std;

int v[10010][6], op[6] = {5, 3, 4, 1, 2, 0};

int f(int idx, int val){
  if(idx == 0)  return 0;
  for(int i = 0; i < 6; ++i)
    if(v[idx][i] == val){
      if(val != 6 && v[idx][op[i]] != 6)  return 6 + f(idx - 1, v[idx][op[i]]);
      else if(val != 5 && v[idx][op[i]] != 5) return 5 + f(idx - 1, v[idx][op[i]]);
      return 4 + f(idx - 1, v[idx][op[i]]);
    }
}

int main(){
  int n, ans = -1;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j < 6; ++j)  scanf("%d", &v[i][j]);

  for(int i = 0; i < 6; ++i){
    if(v[n][i] != 6 && v[n][op[i]] != 6)  ans = max(ans, 6 + f(n - 1, v[n][op[i]]));
    else if(v[n][i] != 5 && v[n][op[i]] != 5) ans = max(ans, 5 + f(n - 1, v[n][op[i]]));
    else ans = max(ans, 4 + f(n - 1, v[n][op[i]]));
  }

  printf("%d\n", ans);
  return 0;
}
