#include <bits/stdc++.h>

using namespace std;

vector <int> a, b;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, x, y;
  cin >> n >> m;
  a.push_back(1);
  b.push_back(n);
  for(int i = 0; i < m; ++i){
    cin >> x >> y;
    a.push_back(min(x, y));
    b.push_back(max(x, y));
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  cout << max(b[0] - a[0], 0) << "\n";

  return 0;
}
