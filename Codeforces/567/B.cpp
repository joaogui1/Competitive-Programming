#include <bits/stdc++.h>

using namespace std;

set <int> s;

int main(){
  ios_base::sync_with_stdio(0);
  char op;
  int n, x, ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> op >> x;
    if(op == '+'){
      s.insert(x);
      ans = max(ans, (int)s.size());
    }
    else{
      if(s.count(x))  s.erase(x);
      else  ans += 1;
    }
  }
  cout << ans << "\n";
 return 0;

}
