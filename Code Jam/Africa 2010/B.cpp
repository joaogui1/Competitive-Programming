#include <bits/stdc++.h>

using namespace std;

vector <string> ans;

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  string s, aus;
  cin >> n;
  getline(cin, aus);
  for(int i = 1; i <= n; ++i){
    ans.clear();
    getline(cin, s);
    stringstream ss(s);
    while(ss >> aus)
      ans.push_back(aus);
    cout << "Case #" << i << ": ";
    for(int j = ans.size() - 1; j > -1; --j)
      cout << ans[j] << " \n"[j == 0];
  }


  return 0;
}
