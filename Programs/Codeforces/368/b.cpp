#include <bits/stdc++.h>

using namespace std;

set<int> s;
int a[100010], ans[100010];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, b;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = n; i > 0; --i){
    s.insert(a[i]);
    ans[i] = s.size();
  }
  for(int i = 0; i < m; ++i){
    cin >> b;
    cout << ans[b] << "\n";
  }


  return 0;
}
