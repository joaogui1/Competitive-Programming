#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  int n, aux1, aux2, sum = 0, tot1 = 0, tot2 = 0, ans = 0, win;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> aux1 >> aux2;
    tot1 += aux1, tot2 += aux2;
    sum = tot2 - tot1;
    if(ans < abs(sum)){
      ans = abs(sum);
      win = (sum > 0)?2:1;
    }
  }

  cout << win << " " << ans << "\n";


}
