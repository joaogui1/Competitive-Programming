#include <bits/stdc++.h>

using namespace std;

int mark[100100], jump[100100], dir[100100];

int main(){
  ios_base::sync_with_stdio(0);
  int n, a = 1;
  char op;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> op;
    if(op == '>') dir[i] = 1;
    else  dir[i] = -1;
  }
  for(int i = 1; i <= n; ++i) cin >> jump[i];
  while(!mark[a]){
    mark[a] = 1;
    a += jump[a]*dir[a];
    if(a > n || a < 1){
      cout << "FINITE\n";
      break;
    }
    if(mark[a]){
      cout << "INFINITE\n";
      break;
    }
  }



  return 0;
}
