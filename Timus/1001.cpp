#include <bits/stdc++.h>

using namespace std;

vector <double> v;
int main(){
  //ios_base::sync_with_stdio(0);
  double aux, ans;
  //cout << setprecision(4);
  //cout << fixed;
  while(scanf("%lf", &aux) != EOF) v.push_back(aux);
  for(int i = v.size() - 1; i > -1; --i) printf("%0.4lf\n", sqrt(v[i]));

  return 0;
}
