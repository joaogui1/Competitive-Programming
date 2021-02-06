#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

set <pii> ans;
vector <int> v;

void valid(int dh, int dm, int n, int m){
  int mins = 0, hrs = 0, ex = 1;
  for(int i = 0; i < dm; ++i, ex *= 7)  mins += v[i]*ex;
  if(mins >= m) return;
  ex = 1;
  for(int i = 0; i < dh; ++i, ex *= 7)  hrs += v[i + dm]*ex;
  if(hrs >= n) return;
  ans.insert(pii(hrs, mins));
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, dh = 1, dm = 1, lixo;
  cin >> n >> m;
  for(int i = 0; i < 7; ++i)  v.push_back(i);
  for(int h = 7; h <= n - 1; h *= 7)  ++dh;
  for(int h = 7; h <= m - 1; h *= 7)  ++dm;
  if(dm + dh > 7){
    cout << "0\n";
    return 0;
  }
  while(1){
    valid(dh, dm, n, m);
    if(!next_permutation(v.begin(), v.end())) break;
  }
  cout << ans.size() << "\n";
  return 0;
}
