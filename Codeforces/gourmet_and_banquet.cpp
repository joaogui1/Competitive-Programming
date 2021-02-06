#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int cnt, cor[10100];
vector <pii> v;

bool cmp(pii a, pii b){
  return a.ss < b.ss;
}

bool vdc(int n){
  ++cnt;
  int acc;
  for(int i = 0; i < v.size(); ++i){
    acc = 0;
    for(int j = v[i].ff; j < v[i].ss; ++j){
      if(acc == n)  break;
      if(cor[j] != cnt) cor[j] = cnt, ++acc;
    }
    if(acc < n) return 0;
  }
  return 1;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, bottom, top, m;
  cin >> n;
  v.assign(n, pii(0, 0));
  for(int i = 0; i < n; ++i)
    cin >> v[i].ff >> v[i].ss;

  sort(v.begin(), v.end(), cmp);
  bottom = 0, top = 10001;
  while(top - bottom > 1){
    m = (top + bottom)/2;
    if(vdc(m))  bottom = m;
    else  top = m;
  }

  cout << bottom*n << "\n";
  return 0;
}
