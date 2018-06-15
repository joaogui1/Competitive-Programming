#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int n;
ll a[128];

ll sum_d(int m){
  ll ret = 0LL;
  for(int i = m; i <= n; i += m)  ret += a[i];
  return ret;
}

void erase_d(int m){
  for(int i = m; i <= n; i += m)  a[i] = 0LL;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll sum = 0, test;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  for(int i = n; i > 0; --i){
    test = sum_d(i);
    if(test < 0){
      erase_d(i);
      sum -= test;
    }
  }

  cout << sum << "\n";

  return 0;
}
