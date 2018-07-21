#include <bits/stdc++.h>

using namespace std;

string s, t;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  bool tst;
  cin >> s >> t;
  if(s.size() != t.size()){
    cout << "No\n";
    return 0;
  }
  for(int i = 0; i < s.size(); ++i){
    tst = 1;
    for(int j = 0; j < s.size(); ++j)
      tst &= (s[(i + j)%s.size()] == t[j]);
    if(tst){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}
