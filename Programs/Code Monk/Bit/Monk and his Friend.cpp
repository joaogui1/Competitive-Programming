#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int ones(ll x){
  if(x == 0)  return 0;
  int ret;
  for(ret = 0; x > 0; x -= x&-x, ++ret);
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  ll n, m, aux;
  cin >> t;
  while(t--){
    cin >> n >> m;
    aux = (n ^ m)&(~(n & m));
    cout << ones(aux) << "\n";
  }




}
