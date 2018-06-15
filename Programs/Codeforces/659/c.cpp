#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

set <ll> s;
vector <ll> ans;

int main(){
  ios_base::sync_with_stdio(0);
  ll aux, n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> aux;
    s.insert(aux);
  }

  for(int i = 1;  m > 0; ++i){
    if(s.count(i))  continue;
    if(i > m) break;
    m -= i;
    ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i == (int)ans.size() - 1];


  return 0;
}
