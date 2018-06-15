#include <bits/stdc++.h>

using namespace std;

int ans[16];
map <string, int> dict;
map <int, string> _dict;

void initialize(){
  dict.clear();
  _dict.clear();
  memset(ans, 0, sizeof ans);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, aux, auq;
  bool blank = 0;
  string aus, aur;
  while(cin >> n){
    initialize();
    for(int i = 0; i < n; ++i){
      cin >> aus;
      dict[aus] = i;
      _dict[i] = aus;
    }
    if(blank) cout << "\n";
    blank = 1;
    for(int i = 0; i < n; ++i){
      cin >> aus >> aux >> auq;
      if(auq == 0)  continue;
      ans[dict[aus]] -= aux;
      if(aux % auq != 0){
        ans[dict[aus]] += aux % auq;
        aux -= (aux % auq);
      }
      for(int j = 0; j < auq; ++j){
        cin >> aur;
        ans[dict[aur]] += aux/auq;
      }
    }
    for(int i = 0; i < n; ++i)
    cout << _dict[i] << " " << ans[i] << "\n";
  }


  return 0;
}
