#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(0);
  ll n, p, aux, sum = 0, ans = 0;
  cin >> n >> p;
  while(n--){
    cin >> aux;
    aux -= p;
    sum += aux;
    ans = max(ans, sum);
    if(sum < 0) sum = 0;
  }
  cout << ans << "\n";

  return 0;
}
