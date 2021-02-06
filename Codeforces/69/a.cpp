#include <bits/stdc++.h>

using namespace std;

string ans[2] = {"NO\n", "YES\n"};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, aux, auy, auz, x = 0, y = 0, z = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux >> auy >> auz;
    x += aux, y += auy, z += auz;
  }
  cout << ans[(x == 0 && y == 0 && z == 0)];

  return 0;
}
