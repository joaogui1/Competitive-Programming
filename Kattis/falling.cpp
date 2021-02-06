#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n1, n2, d, c;
  cin >> d;
  if(d % 4 == 2)  cout << "impossible\n";
  else{
    if(d % 2 == 0){
      c = (d - 4)/4;
      n1 = c, n2 = c + 2;
    }
    else{
      c = (d - 1)/2;
      n1 = c, n2 = c + 1;
    }
    cout << n1 << " " << n2 << "\n";
  }


  return 0;
}
