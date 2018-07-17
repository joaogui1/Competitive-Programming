#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector <ll> v[3];
ll sum[500100], aux, ans = 0;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  vector <ll>::iterator it, itt;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> aux;
    sum[i] = sum[i - 1] + aux;
  }
  if(sum[n]%3 != 0){
    cout << 0 << "\n";
    return 0;
  }
  for(int i = 1; i < n; ++i){
    if(sum[i] == sum[n]/3)  v[0].push_back(i);
    if(sum[i] == 2*sum[n]/3)  v[1].push_back(i);
    if(sum[i] == sum[n])  v[2].push_back(i);
  }
  for(int i = 0; i < v[0].size(); ++i){
    it = upper_bound(v[1].begin(), v[1].end(), v[0][i]);
    ans += (v[1].end() - it);
    // for(; it != v[1].end(); ++it)
    //   ans += v[2].end() - (upper_bound(v[2].begin(), v[2].end(), *it));
  }
  cout << ans << "\n";
  return 0;
}
