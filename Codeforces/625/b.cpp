#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int ans = 0;
  string a, b;
  cin >> a >> b;
  for(int i = 0; i < a.size(); ++i){
    if(i + b.size() - 1 >= a.size())  break;
    if(a.substr(i, b.size()) == b){
      ++ans;
      i += b.size() - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
