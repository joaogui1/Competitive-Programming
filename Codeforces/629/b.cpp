#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> pii;

pii v[400];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, a, b,ans = -1;
  char ty;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> ty >> a >> b;
    for(int j = a; j <= b; ++j){
      if(ty == 'M') ++v[j].ff;
      else  ++v[j].ss;
    }
  }
  for(int i = 1; i < 367; ++i)  ans = max(ans, 2*min(v[i].ff, v[i].ss));
  cout << ans << "\n";
  return 0;
}
