#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string p;
int z[1000100];

void f(){
  z[0] = p.size();
  int l, r;
  l = r = -1;
  for(int i = 1; i < p.size(); ++i){
    z[i] = 0;
    if(i < r) z[i] = min(z[i - l], r - i);
    while(i + z[i] < p.size() && p[i + z[i]] == p[z[i]])  ++z[i];
    if(i + z[i] > r){
      l = i;
      r = i + z[i];
    }
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  bool vdc = 1;
  long long int ans = 1;
  int n, m, l = 1, pos, cnt = 0;
  cin >> n >> m >> p;

  f();

  for(int i = 0; i < m && vdc; ++i){
    cin >> pos;
    if(pos >= l)  cnt += pos - l;
    else if(z[pos - l + p.size()] < l - pos)  vdc = 0;
    l = pos + p.size();
  }
  cnt += n - l + 1;
  ans = vdc;
  for(int i = 0; i < cnt; ++i)  ans *= 26, ans %= MOD;

  cout << ans << "\n";

  return 0;
}
