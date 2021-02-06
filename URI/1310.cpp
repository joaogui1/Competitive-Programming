#include <bits/stdc++.h>

using namespace std;

int kad[1010];

int f(int n){
  int ret = 0, test = 0;
  for(int i = 0; i < n; ++i){
    test += kad[i];
    if(test < 0)  test = 0;
    if(test > ret)  ret = test;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int n, cost;
  while(cin >> n){
    memset(kad, 0, sizeof kad);
    cin >> cost;
    for(int i = 0; i < n; ++i)  cin >> kad[i];
    for(int i = 0; i < n; ++i)  kad[i] -= cost;
    cout << f(n) << "\n";
  }

  return 0;
}
