#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  ll aux, ans = 0;
  cin >> n;
  while(n--){
    cin >> aux;
    ans += aux - 1;
  }

  cout << ans << "\n";
  return 0;
}
