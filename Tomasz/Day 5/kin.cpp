#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int fr[8096], v[8096];
long long int w[8096];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  long long int test, best = -1;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)  cin >> v[i];
  for(int i = 1; i <= m; ++i)  cin >> w[i];
  for(int i = 1; i <= n; ++i){
    test = 0;
    memset(fr, 0, sizeof fr);
    for(int j = i; j <= n; ++j){
      ++fr[v[j]];
      if(fr[v[j]] == 1){
        test += w[v[j]];
        if(test > best) best = test;
      }
      if(fr[v[j]] == 2) test -= w[v[j]];
    }
  }
  cout << best << "\n";
  return 0;
}
