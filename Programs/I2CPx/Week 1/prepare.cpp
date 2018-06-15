#include <bits/stdc++.h>

using namespace std;

int p[128], t[128];
int main(){
  ifstream fin("prepare.in");
  ofstream fout("prepare.out");
  int n, idx = 0, ans = 0;
  fin >> n;
  for(int i = 0; i < n; ++i)  fin >> p[i];
  for(int i = 0; i < n; ++i)  fin >> t[i];
  for(int i = 0; i < n; ++i)
    ans += max(p[i], t[i]);
  if(p[0] > t[0])
    for(int i = 0; i < n; ++i)
      if(p[i] - t[i] < p[idx] - t[idx])
        idx = i;
      if(p[idx] - t[idx] > 0)
        ans -= (p[idx] - t[idx]);
  else
    for(int i = 0; i < n; ++i)
      if(t[i] - p[i] < t[idx] - p[idx])
        idx = i;
      if(t[idx] - p[idx] > 0)
        ans -= (t[idx] - p[idx]);

  fout << ans << "\n";


  return 0;
}
