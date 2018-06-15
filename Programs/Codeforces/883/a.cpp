#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll crt(ll x){
  ll ini = 0, m, fim = 1000001;
  while(fim - ini > 1){
    m = (fim + ini)/2;
    if(m*m*m < x) ini = m;
    if(m*m*m > x) fim = m;
    if(m*m*m == x)  return m;
  }
  return m;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, a, b, x;
  cin >> n;
  while(n--){
    cin >> a >> b;
    x = crt(a*b);
    // cout << x << " ";
    if(x*x*x != a*b)  cout << "No\n";
    else if(a%x != 0 || b%x != 0) cout << "No\n";
    else  cout << "Yes\n";
  }






  return 0;
}
