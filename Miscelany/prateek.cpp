#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll v[2 << 20];

int main(){
  ios_base::sync_with_stdio(0);
  int t, beg;
  ll n, x, sum;
  cin >> t;
  while(t--){
    cin >> n >> x;
    sum = 0LL;
    beg = 0;
    memset(v, 0, sizeof v);
    for(int i = 0; i < n; ++i)  cin >> v[i];
    for(int i = 0; i < n; ++i){
      sum += v[i];
      while(sum > x)  sum -= v[beg++];
      if(sum == x)  break;
    }
    if(sum == x)  cout << "YES\n";
    else  cout << "NO\n";
  }




  return 0;
}
