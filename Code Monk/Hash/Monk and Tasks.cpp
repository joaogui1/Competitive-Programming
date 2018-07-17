#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<ll> ans[61];

void initialize(){
  for(int i = 0; i < 61; ++i) ans[i].clear();
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n, ones;
  ll aux;
  cin >> t;
  while(t--){
    cin >> n;
    initialize();
    while(n--){
      cin >> aux;
      ones = 0;
      for(ll i = aux; i; i/=2)  if(i&1) ++ones;
      ans[ones].push_back(aux);
    }
    for(int i = 0; i < 61; ++i)
      for(int j = 0; j < ans[i].size(); ++j)
        cout << ans[i][j] << " ";
    cout << "\n";
  }


  return 0;
}
