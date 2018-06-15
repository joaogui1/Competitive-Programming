#include <bits/stdc++.h>

using namespace std;

int val[16];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int k;
  char aux;
  cin >> k;
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j){
      cin >> aux;
      if(aux != '.')  ++val[aux - '0'];
    }
  for(int i = 0; i < 10; ++i){
    if(val[i] > 2*k){
      cout << "NO\n";
      break;
    }
    if(i == 9)  cout << "YES\n";
  }
  return 0;
}
