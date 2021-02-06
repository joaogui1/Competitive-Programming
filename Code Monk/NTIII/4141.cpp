#include <bits/stdc++.h>
#define MAXN (1LL << 59LL)

using namespace std;
typedef long long int ll;

ll pot[50010], a[50010];

void inintialize(){
  pot[0] = 1;
  for(int i = 1; i < 50010; ++i){
    pot[i] = pot[i - 1]*10LL;
    if(pot[i] > MAXN) pot[i] %= 41LL;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  int t, n;
  ll ans, c;
  cin >> t;
  inintialize();

  while(t--){
    ans = 0LL;
    cin >> a[0] >> a[1] >> c >> n;
    for(int i = 2; i < n; ++i)
      a[i] = (a[i - 1]*c + a[i - 2]) % 10LL;
    for(int i = 0; i < n; ++i){
      if(ans > MAXN - a[i]*pot[n - 1 - i])  ans %= 41LL;
      ans += a[i]*pot[n - 1 - i];
    }
    ans %= 41LL;
    if(ans == 0LL)  cout << "YES\n";
    else  cout << "NO\n";
  }

  return 0;
}
