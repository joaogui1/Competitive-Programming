#include <bits/stdc++.h>

using namespace std;

double a[4][4];
int main(){
  ifstream fin("team.in");
  ofstream fout("team.out");
  double ans = 0;
  vector <int> v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      fin >> a[i][j];
  while(1){
    ans = max(ans, sqrt(a[0][v[0]]*a[0][v[0]] + a[1][v[1]]*a[1][v[1]] + a[2][v[2]]*a[2][v[2]]));
    if(!next_permutation(v.begin(), v.end())) break;
  }
  fout << fixed << setprecision(10) << ans << "\n";

  return 0;
}
