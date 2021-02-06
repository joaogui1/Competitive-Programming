#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int idx;
  string s, t;
  while(cin >> s >> t){
    idx = 0;
    for(int i = 0; i < t.size(); ++i) if(s[idx] == t[i])  ++idx;
    if(idx == s.size()) cout << "Yes\n";
    else  cout << "No\n";
  }


  return 0;
}
