#include <bits/stdc++.h>

using namespace std;

string s;
set <string> ans;

void f(){
  string ret = "";
  for(int i = 0; i < (1 << s.size()); ++i){
    ret = "";
    for(int j = 0; j < s.size(); ++j){
      if(i & (1 << j))
        ret = s[j] + ret;
      else  ret += s[j];
    }
    //cout << ret << endl;
    ans.insert(ret);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int q = 1; q <= t; ++q){
    ans.clear();
    cin >> s;
    f();
    //cout << ans.size() << endl;
    cout << "Case #" << q << ": " << *(--ans.end()) << "\n";
  }



  return 0;
}
