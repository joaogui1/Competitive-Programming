#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

ll a[100100] = {0}, t[100100] = {0}, pos[100100], sz[100100] = {0};
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll n, at, ant = MOD, ans = 1;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> t[i];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i){
    sz[i] = t[i];
    if(t[i] > t[i - 1])
      pos[i] = 1;
    else
      pos[i] = t[i];
  }
  for(int i = 1; i <= n; ++i){
    if(a[i] > a[i - 1]){
      if(a[i] != 0 && a[i] != sz[n - i + 1]) pos[n - i + 1] = 0;
      else  pos[n - i + 1] = 1;
    }
    else{
      pos[n - i + 1] = min(pos[n - i + 1], a[i]);
    }
  }
  for(int i = 1; i <= n; ++i) cout << pos[i] << " \n"[i == n];
  for(int i = 1; i <= n; ++i){
    ans *= pos[i];
    if(ans > MOD) ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
