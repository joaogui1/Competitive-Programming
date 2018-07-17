#include <bits/stdc++.h>

using namespace std;

int speed[128];

int main(){
  ios_base::sync_with_stdio(0);
  int n, m, ans = 0, x, v, beg = 0;
  ifstream fin ("speeding.in");
  ofstream fout ("speeding.out");
  fin >> n >> m;
  for(int i = 0; i < n; ++i){
    fin >> x >> v;
    for(int i = beg; i < beg + x; ++i)
      speed[i] = v;
    beg += x;
  }
  beg = 0;
  for(int i = 0; i < m; ++i){
    fin >> x >> v;
    for(int i = beg; i < beg + x; ++i)
      ans = max(ans, v - speed[i]);
    beg += x;
  }
  fout << ans << "\n";

  return 0;
}
