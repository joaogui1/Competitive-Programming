#include <bits/stdc++.h>

using namespace std;

int freq[100010];
multiset <int> sa, sb;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a;
    sa.insert(-a);
  }
  for(int i = 0; i < m; ++i){
    cin >> a;
    while(a > 0 && sa.size()){
      b = *(sa.begin());
      sa.erase(sa.begin());
      sb.insert(b + 1);
      --a;
    }
    if(a > 0){
      cout << "NIE\n";
      return 0;
    }
    while(sb.size()){
      if(*(sb.begin()) < 0) sa.insert(*(sb.begin()));
      sb.erase(sb.begin());
    }
  }
  cout << "TAK\n";


  return 0;
}
