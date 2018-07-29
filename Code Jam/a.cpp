#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int mark[16];

void mrk(ll x){
  for(; x > 0; x /= 10LL)
    mark[x % 10] = 1;
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  ll n;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cin >> n;
    memset(mark, 0, sizeof mark);
    cout << "Case #" << i << ": ";
    for(ll j = 1; j <= 10000000LL; ++j){
      mrk(j*n);
      for(int k = 0; k <= 9; ++k){
        if(mark[k] == 0)  break;
        else if(k == 9){
          cout << j*n << "\n";
          j = 10000001LL;
          break;
        }
      }
      if(j == 10000000LL) cout << "INSOMNIA\n";
    }
  }



  return 0;
}
