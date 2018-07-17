#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a;
  cin >> n;
  v.assign(n, 0);
  for(int i = 0; i < n; ++i)  cin >> v[i];
  sort(v.begin(), v.end());
  v[0] = 1;
  for(int i = 1; i < n; ++i)
    if(v[i] >= v[i - 1] + 1)  v[i] = v[i - 1] + 1;
  cout << v[n - 1] + 1 << "\n";

  return 0;
}
