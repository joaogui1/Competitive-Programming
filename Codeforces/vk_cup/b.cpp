#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int fr[150100];
set <pii> scr, _scr;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string ans[2] = {"NO", "YES"};
  int n, k, q, op, id;
  cin >> n >> k >> q;
  for(int i = 1; i <= n; ++i) cin >> fr[i];
  for(int i = 0; i < q; ++i){
    cin >> op >> id;
    if(op == 1){
      if(_scr.size() == k && _scr.begin() -> ff < fr[id]){
        scr.erase(pii(_scr.begin() -> ss, _scr.begin() -> ff));
        _scr.erase(_scr.begin());
        scr.insert(pii(id, fr[id]));
        _scr.insert(pii(fr[id], id));
      }
      else if(scr.size() < k){
        scr.insert(pii(id, fr[id]));
        _scr.insert(pii(fr[id], id));
      }
      //for(pii el: scr)  cout << el.ff << " " << el.ss << "\n";
    }
    else{
      cout << ans[scr.count(pii(id, fr[id]))] << "\n";
    }
  }


  return 0;
}
