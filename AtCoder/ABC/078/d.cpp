#include <bits/stdc++.h>

using namespace std;

int v[2048];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;
  for(int i = 0; i < n; ++i)  cin >> v[i];
  if(n == 1)  cout << abs(v[0] - b) << "\n";
  else  cout << max(abs(v[n - 2] - v[n - 1]), abs(v[n - 1] - b)) << "\n";
  return 0;
}
