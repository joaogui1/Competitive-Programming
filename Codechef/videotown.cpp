#include <bits/stdc++.h>

using namespace std;

int piles[100100];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int pos = 0, carr = 0, n, h, op = 1;
  cin >> n >> h;
  for(int i = 0; i < n; ++i)
    cin >> piles[i];
  while(op){
    cin >> op;
    if(op == 1){
      if(pos > 0) --pos;
    }
    else if(op == 2){
      if(pos < n - 1) ++pos;
    }
    else if(op == 3){
      if(carr == 0 && piles[pos] > 0){
        carr = 1;
        --piles[pos];
      }
    }
    else if(op == 4){
      if(carr == 1 && piles[pos] < h){
        carr = 0;
        ++piles[pos];
      }
    }
  }
  for(int i = 0; i < n; ++i)
    cout << piles[i] << " \n"[i + 1 == n];


  return 0;
}
