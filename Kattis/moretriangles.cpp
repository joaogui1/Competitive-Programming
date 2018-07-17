#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 2; i <= n; ++i){
    int ans = 0;
    set<int> sq;
    for(int j = 1; j < i; ++j)
      sq.insert(j*j % i);
    for(int j = 1; j < i; ++j)
      for(int k = 1; k <= j; ++k)
        if(sq.count(((j*j) + (k*k)) % i)) ++ans;
    cout << ans << " " << sq.size() << endl;
  }



  return 0;
}
