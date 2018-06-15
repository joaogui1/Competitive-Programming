#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll G[128][128];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  char c;
  ll ans = 0, cont;
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
      cin >> c;
      G[i][j] = (c == 'C');
    }
  for(int i = 0; i < n; ++i){
    cont = 0;
    for(int j = 0; j < n; ++j)  cont += G[i][j];
    ans += cont*(cont - 1)/2;
  }
  for(int i = 0; i < n; ++i){
    cont = 0;
    for(int j = 0; j < n; ++j)  cont += G[j][i];
    ans += cont*(cont - 1)/2;
  }
  cout << ans << "\n";
  return 0;
}
