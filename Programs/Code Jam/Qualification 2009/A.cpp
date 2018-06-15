#include <bits/stdc++.h>

using namespace std;

set <char> freq[32];
vector <string> dict;

int main(){
  ios_base::sync_with_stdio(0);
  string aus;
  int l, d, n, sz, ans;
  cin >> l >> d >> n;
  for(int i = 0; i < d; ++i){
    cin >> aus;
    dict.push_back(aus);
  }

  for(int i = 1; i <= n; ++i){
    sz = ans = 0;
    for(int j = 0; j < 32; ++j) freq[j].clear();
    cin >> aus;
    for(int j = 0; j < aus.size(); ++j){
      if(aus[j] != '(')
        freq[sz].insert(aus[j]);
      else{
          ++j;
          for(; j < aus. size() && aus[j] != ')'; ++j){
            freq[sz].insert(aus[j]);
        }
      }
      ++sz;
    }

    /*for(int i = 0; i < sz; ++i){
      for(auto c : freq[i]) cout << c << " ";
      cout << endl;
    }*/


    for(int j = 0; j < d; ++j){
      for(int k = 0; k < sz; ++k){
        if(freq[k].count(dict[j][k]) == 0)  break;
        if(k == sz - 1) ++ans;
      }
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }



  return 0;
}
