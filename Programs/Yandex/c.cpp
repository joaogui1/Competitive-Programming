#include <bits/stdc++.h>

using namespace std;

int mark[16];
double p[16][16];
vector <int> ord;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  double ans = 0.0, prod = 1.0;
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> p[i][j];
  for(int i = 0; i < n; ++i)  ord.push_back(i);
  while(1){
    prod = 1.0;
    memset(mark, 0, sizeof mark);
    for(int i = 0; i < n; ++i){
      mark[ord[i]] = 1;
      for(int j = 0; j < n; ++j)
        if(!mark[j])  prod *= p[ord[i]][j];
    }
    ans += prod;
    if(!next_permutation(ord.begin(), ord.end())) break;
  }
  cout << fixed << setprecision(15) << ans << "\n"; 
  return 0;
}
