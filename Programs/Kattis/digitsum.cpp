#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum(ll n){
  return n ? n%10 + sum(n/10) : 0;
}

ll f(ll n){
  return n < 10 ? (n*(n - 1)/2) : f(n%10) + 45 * (n/10)  + (n%10) * sum(n/10) + 10 * f(n/10);
}

int main(){
  ios_base::sync_with_stdio(0);
  int n;
  ll a, b;
  cin >> n;
  while(n--){
    cin >> a >> b;
    cout << f(b + 1) - f(a) << "\n";
  }

  return 0;
}
