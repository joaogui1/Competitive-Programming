#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int t[16];
int main(){
  ifstream fin ("win.in");
  ofstream fout ("win.out");
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, ans = 0, sum = 0;
  fin >> n;
  for(int i = 0; i < n; ++i)  fin >> t[i];
  sort(t, t + n);
  for(int i = 0; i < n && sum <= 18000; ++i)
    if(sum + t[i] <= 18000)
      ++ans, sum += t[i];
  fout << ans << "\n";
  return 0;
}
