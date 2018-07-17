#include <bits/stdc++.h>
#define MAXM (1LL << 32)

using namespace std;
typedef long long int ll;

vector<ll> v;
map <ll, int> mp;
ll sz, p = 1LL, w, m, sum;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> w >> m;
  if(w < 4){
    cout << "YES\n";
    return 0;
  }
  while(p < MAXM) v.push_back(p), p*= w;

  sz = v.size();
  for(int i = 0; i < (1LL << sz); ++i){
    sum = 0;
    for(int j = 0; j < sz; ++j) if((i&(1LL << j)))  sum += v[j];
    mp[sum] = 1;
  }
  for(pair<ll, int> i: mp){
    if(i.first >= m && mp.count(i.first - m)){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}
