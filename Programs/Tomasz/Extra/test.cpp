#include <bits/stdc++.h>

using namespace std;

double rad(){
  return (double)rand() / (double)RAND_MAX;
}

int main(){
  srand(time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  double ans = 0;
  double x[2];
  for(int i = 0; i < 10000; ++i){
    x[1] = rad();
    for(int j = 2; ; ++j){
      x[j%2] = rad();
      if(x[j%2] > x[(j - 1)%2]){
        ans += j;
        break;
      }
    }
  }
  cout << ans/10000.0 << "\n";


  return 0;
}
