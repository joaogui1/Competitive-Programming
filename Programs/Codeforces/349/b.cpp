#include <bits/stdc++.h>

using namespace std;

int a[16];
vector <int> ans;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int v, idx = 9;
  cin >> v;
  for(int i = 1; i < 10; ++i) cin >> a[i];
  for(int i = 8; i > 0; --i)
    if(a[idx] > a[i]) idx = i;
  while(v >= a[idx]){
    v -= a[idx];
    ans.push_back(idx);
  }
  for(int i = 0; i < ans.size(); ++i){
    for(int j = 9; j > idx; --j)
      if(v + a[idx] >= a[j]){
        v -= (a[j] - a[idx]);
        ans[i] = j;
        break;
      }
  }
  if(ans.size() == 0) cout << "-1";
  else
    for(int i = 0; i < ans.size(); ++i) cout << ans[i];
  cout << "\n";
  return 0;
}
