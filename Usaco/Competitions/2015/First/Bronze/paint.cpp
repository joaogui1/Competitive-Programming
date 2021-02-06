#include <bits/stdc++.h>

using namespace std;

int p[128];

int main(){
  ios_base::sync_with_stdio(0);
  int a, b, c, d, ans = 0;
  ifstream fin ("paint.in");
  ofstream fout ("paint.out");
  fin >> a >> b >> c >> d;
  for(int i = a; i < b; ++i)  p[i] = 1;
  for(int i = c; i < d; ++i)  p[i] = 1;
  for(int i = 0; i < 101; ++i)  ans += p[i];
  fout << ans << "\n";
}
