#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long int ll;

vector <ll> a;
vector <ll> b;

ll fa(int l, int r){
  ll ret = 0;
  for(int i = l; i <= r; ++i)
    ret |= a[i];
  return ret;
}

ll fb(int l, int r){
  ll ret = 0;
  for(int i = l; i <= r; ++i)
    ret |= b[i];
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll aux, ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux;
    a.push_back(aux);
  }
  for(int i = 0; i < n; ++i){
    cin >> aux;
    b.push_back(aux);
  }
  for(int i = 0; i < n; ++i)
    for(int j = i; j < n; ++j){
      //cout << i << " " << j << " " << fa(i, j) << " " << fb(i, j) << "\n";
      ans = max(ans, fa(i, j) + fb(i, j));
    }
  cout << ans << "\n";

  return 0;
}
