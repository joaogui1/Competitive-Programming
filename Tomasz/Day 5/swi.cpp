#include <bits/stdc++.h>

using namespace std;

int p[500010], r[500010];

int find(int x){
  return (p[x] == x)?x:(p[x] = find(p[x]));
}

void join(int x, int y){
  //p[find(x)] = p[find(y)];
  x = find(x), y = find(y);
  if(r[x] < r[y]){
    p[x] = y;
    return;
  }
  p[y] = x;
  if(r[y] == r[x])  ++r[y];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b, l, ans = 0;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) p[i] = i, r[i] == 1;
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> l;
    for(int i = 0; i < l; ++i)
      join(a + i, b + i);
  }
  for(int i = 1; i <= n; ++i)
    ans += (p[i] == i);
  cout << ans << "\n";
  return 0;
}
