#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

vector <pii> v;
vector <pii> ans;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pii aup;
  int n, m;
  cin >> n >> m;
  v.resize(m);
  for(int i = 0; i < m; ++i)  cin >> v[i].ff >> v[i].ss;
  sort(v.begin(), v.end());
  ans.push_back(v[0]);
  for(int i = 1; i < v.size(); ++i){
    if(ans.size() && v[i].ff < min(v[i].ss, ans.back().ss)){
      aup = ans.back(), ans.pop_back();
      aup.ff = v[i].ff;
      aup.ss = min(aup.ss, v[i].ss);
      ans.push_back(aup);
    }
    else  ans.push_back(v[i]);
  }
  cout << ans.size() << "\n";

  return 0;
}
