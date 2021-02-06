#include <bits/stdc++.h>

using namespace std;

set <int> lod;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k, b, pos = 0;
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> b;
    if(b) lod.insert(i);
  }
  for(int cont = 1; ; ++cont){
    b = *(--lod.upper_bound(pos + k));
    if(b == pos){
      cout << "-1\n";
      return 0;
    }
    pos = b;
    if(pos == n - 1){
      cout << cont << "\n";
      return 0;
    }
  }
  return 0;
}
