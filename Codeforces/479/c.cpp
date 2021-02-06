#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

vector <pii> v;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, t = 0, val = 0;
  cin >> n;
  v.assign(n, pii(0, 0));
  for(int i = 0; i < n; ++i)
    cin >> v[i].ff >> v[i].ss;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; ++i){
    if(t <= v[i].ss) t = v[i].ss;
    else  t = v[i].ff;
  }

  cout << t << "\n";
  return 0;
}
